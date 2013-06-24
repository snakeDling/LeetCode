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
    vector<vector<int>> result;
    vector<int> path;
    
    void findPath(TreeNode *root, int sum){
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(sum - root->val == 0){
                result.push_back(path);
            }
        }else{
            if(root->left != NULL)
                findPath(root->left, sum - root->val);
            if(root->right != NULL)
                findPath(root->right, sum - root->val);
        }
        path.pop_back();
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        path.clear();
        if(root != NULL)
            findPath(root, sum);
        return result;
    }
};