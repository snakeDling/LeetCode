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
    bool cmpSubTree(TreeNode *l, TreeNode *r){
        if(l == NULL || r == NULL){
            return l==r;
        }
        if(l->val != r->val)
            return false;
        else{
            if(!cmpSubTree(l->left, r->right))
                return false;
            else
                return cmpSubTree(l->right, r->left);
        }
    }
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
        else
            return cmpSubTree(root->left, root->right);
    }
};