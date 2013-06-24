/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL)
            return sum - root->val == 0;
        if(root->left != NULL)
            if(hasPathSum(root->left, sum - root->val))
                return true;
        if(root->right != NULL)
            return hasPathSum(root->right, sum - root->val);
        else
            return false;
        
    }
};