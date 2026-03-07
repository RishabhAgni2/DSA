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
    unordered_map<int,vector<TreeNode*>> dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(dp.count(n)) return dp[n];
        
        vector<TreeNode*> result;
        
        if(n == 1){
            result.push_back(new TreeNode(0));
            return dp[n] = result;
        }
        
        if(n % 2 == 0) return result;
        
        for(int left = 1; left < n; left += 2){
            
            int right = n - 1 - left;
            
            vector<TreeNode*> leftTrees = allPossibleFBT(left);
            vector<TreeNode*> rightTrees = allPossibleFBT(right);
            
            for(auto l : leftTrees){
                for(auto r : rightTrees){
                    
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    
                    result.push_back(root);
                }
            }
        }
        
        return dp[n] = result;
    }
};