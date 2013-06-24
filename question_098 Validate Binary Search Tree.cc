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
    int pre;
    bool isValid(TreeNode *root){
        if(root == NULL)
            return true;
        if(isValid(root->left)){
            if(root->val > pre){
                pre = root->val;
                return isValid(root->right);
            }
        }
        return false;
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        pre = 0x80000000;
        return isValid(root);
    }
};