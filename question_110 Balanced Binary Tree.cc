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
    int subDepth(TreeNode *root){
        if(root == NULL)
            return 0;
        int l=subDepth(root->left);
        if(l== -1)
            return l;
        int r=subDepth(root->right);
        if(r == -1)
            return r;
        if(abs(l-r) > 1)
            return -1;
        else
            return max(r,l)+1;
    }

    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int depth = subDepth(root);
        if(depth == -1)
            return false;
        else
            return true;
    }
};