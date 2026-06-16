/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
void markPar(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &nodetoparent){
    queue<TreeNode*> q;
    q.push(root);
    nodetoparent[root]=NULL;
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(node->left){
            q.push(node->left);
            nodetoparent[node->left] = node;
        }
        if(node->right){
            q.push(node->right);
            nodetoparent[node->right]=node;
        }
    }
}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         unordered_map<TreeNode*, TreeNode*> nodetoparent;
         markPar(root,nodetoparent);
         vector<int> ans;
         unordered_map<TreeNode*,bool> visited;
         queue<TreeNode*> q;
         q.push(target);
         visited[target]=true;
         int dist = 0;
         while(!q.empty()){
            int size = q.size();
            if(dist==k)break;
            dist++;
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left && !visited[front->left]){
                    visited[front->left]=true;
                    q.push(front->left);
                }
                if(front->right && !visited[front->right]){
                    visited[front->right]=true;
                    q.push(front->right);
                }
                if(nodetoparent[front] && !visited[nodetoparent[front]]){
                    visited[nodetoparent[front]]=true;
                    q.push(nodetoparent[front]);
                }
            }
         }
         while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
         }
         return ans;
    }
};