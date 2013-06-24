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
    int total;
    
    void findLeaf(TreeNode *root, int sum){
        sum = sum*10 + root->val;
        if(root->left == NULL && root->right == NULL){
            total += sum;
        }else{
            if(root->left != NULL){
                findLeaf(root->left, sum);
            }
            if(root->right != NULL){
                findLeaf(root->right, sum);
            }
        }
    }
    
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        total=0;
        if(root!=NULL)
            findLeaf(root, 0);
        return total;
    }
};