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
    int maxSum;
    int findSum(TreeNode *root){
        if(root == NULL)
            return 0;
        int l = max(findSum(root->left), 0);
        int r = max(findSum(root->right), 0);
        maxSum = max(maxSum, l+r+root->val);
        return max(l, r) + root->val;
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        maxSum = 0x80000000;
        findSum(root);
        return maxSum;
    }
};