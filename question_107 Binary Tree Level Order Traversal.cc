    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        if(root == NULL)
            return result;
        queue<TreeNode*> _p;
        _p.push(root);
        int count=0, pre_count=1;
        while(pre_count != 0){
            vector<int> level_values;
            TreeNode* cur;
            for(int i=0; i< pre_count; ++i){
                cur = _p.front();
                _p.pop();
                level_values.push_back(cur->val);
                if(cur->left != NULL){
                    _p.push(cur->left);
                    ++count;
                }
                if(cur->right != NULL){
                    _p.push(cur->right);
                    ++count;
                }
            }
            pre_count = count;
            count = 0;
            result.push_back(level_values);
        }
        return result;
    }
