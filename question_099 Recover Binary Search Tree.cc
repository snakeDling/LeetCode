//常数空间的解 
    TreeNode* pre;
    TreeNode* tag;
    TreeNode* tag_2;
    void init(TreeNode* root){
        pre = NULL;
        tag = NULL;
    }

    void change(TreeNode* r, TreeNode* l){
        int tmp = r->val;
        r->val = l->val;
        l->val = tmp;
    }

    void vist(TreeNode* cur){
        if(pre != NULL && cur->val < pre->val){
            if(tag == NULL){
                tag = pre;
                tag_2 = cur;
            }else{
                change(tag, cur);
            }
        }
        pre = cur;
    }
    
    void end(){
        if(tag_2->val < tag->val)
            change(tag, tag_2);
    }
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        init(root);
        while(root != NULL){
            if(root->left == NULL){
                vist(root);
                root = root->right;
            }else{
                TreeNode* r_est = root->left;
                while(r_est->right != NULL && r_est->right != root){r_est=r_est->right;}
                if(r_est->right == NULL){
                    r_est->right = root;
                    root = root->left;
                }else{
                    vist(root);
                    r_est->right = NULL;
                    root = root->right;
                }
            }
        }
        end();
    }