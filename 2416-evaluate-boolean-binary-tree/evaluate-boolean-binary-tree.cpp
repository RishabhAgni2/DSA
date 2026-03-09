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
    bool evaluateTree(TreeNode* root) {
        // If node is a leaf node
        if(root->left == NULL && root->right == NULL)
            return root->val;   // 0 -> false, 1 -> true
        
        // Recursively evaluate left subtree
        bool left = evaluateTree(root->left);
        
        // Recursively evaluate right subtree
        bool right = evaluateTree(root->right);
        
        // If node value is 2 → OR operation
        if(root->val == 2)
            return left || right;
        
        // If node value is 3 → AND operation
        return left && right;
    }
};