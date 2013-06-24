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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result(1, vector<int>());
        queue<TreeNode*> q;
        int curLevelSize=1;
        int nextLevelSize=0;
        bool bReverse = false;
        while(!q.empty() || root != NULL){
            if(root != NULL){
                result.back().push_back(root->val);
                q.push(root->left);
                q.push(root->right);
                nextLevelSize += 2;
            }
            root = q.front();
            q.pop();
            if(--curLevelSize == 0){
                if(bReverse){
                    reverse(result.back().begin(), result.back().end());
                }
                result.push_back(vector<int>());
                bReverse = bReverse == false;
                curLevelSize = nextLevelSize;
                nextLevelSize = 0;
            }
        }
        result.pop_back();
        return result;
    }
};