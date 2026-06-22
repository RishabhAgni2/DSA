/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    pair<int,int> dfs(TreeNode* root,int &ans){
        if(!root){
            return {0,0};
        }
        auto left = dfs(root->left,ans);
        auto right = dfs(root->right,ans);

        int sum = left.first + right.first+  root->val;
        int nodes = left.second + right.second + 1;
        if(root->val==sum/nodes){
            ans++;
        }
        return {sum,nodes};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        dfs(root,ans);
        return ans;
    }
};