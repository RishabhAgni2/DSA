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
public:
    unordered_map<string,int> freq;
    vector<TreeNode*> ans;
    string dfs(TreeNode* node){
        if(node==nullptr){
            return "#";
        }
        string left  = dfs(node->left);
        string right = dfs(node->right);
        string serial = to_string(node->val)+","+left+","+right;
        freq[serial]++;
        if(freq[serial]==2){
            ans.push_back(node);
        }
        return serial;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};