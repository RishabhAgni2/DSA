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
    bool isleaf(TreeNode* root){
        if(root->left==NULL&&root->right==NULL)return true;
        return false;
    }
private:
    void getpathSum(TreeNode* root,int &ans,int curr){
        curr = curr*10 + root->val;
        if(isleaf(root)){
            ans+=curr;
            return;
        }
        if(root->left)getpathSum(root->left,ans,curr);
        if(root->right)getpathSum(root->right,ans,curr);
        return;
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int curr = 0;
        if(root==NULL)return ans;
        getpathSum(root,ans,curr);
        return ans;
    }
};