//递归版
    void traversal(TreeNode* cur, vector<int> &result){
        if(cur == NULL){
            return;
        }
        traversal(cur->left, result);
        result.push_back(cur->val);
        traversal(cur->right, result);
    }
    
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        traversal(root, result);
        return result;
    }


//类递归堆栈版
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        vector<TreeNode*> stack;
        TreeNode *cur = root;
        while(!stack.empty() || cur!=NULL){
            if(cur == NULL){
                cur = stack.back();
                continue;
            }
            if(stack.empty() || cur != stack.back()){
                stack.push_back(cur);
                cur = cur->left;
                continue;
            }
            result.push_back(cur->val);
            stack.pop_back();
            cur = cur->right;      
        }
        return result;
    }
    
    //空间O(1)非递归版
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        TreeNode *cur = root;
        TreeNode* r_est = NULL;
        while(cur != NULL){
            if(cur->left == NULL){
                result.push_back(cur->val);
                cur = cur->right;
                continue;
            }else{
                r_est = cur->left;
                while(r_est->right != NULL && r_est->right != cur){r_est = r_est->right;}
                if(r_est->right == NULL){
                    r_est->right = cur;
                    cur = cur->left;
                }else{
                    result.push_back(cur->val);
                    r_est->right = NULL;
                    cur = cur->right;
                }
            }
        }
    }