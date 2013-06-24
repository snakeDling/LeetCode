    TreeNode* copyTree(TreeNode* node, int offset){
        if(node == NULL)
            return NULL;
        TreeNode* copy = new TreeNode(node->val+offset);
        copy->left = copyTree(node->left, offset);
        copy->right = copyTree(node->right, offset);
    }
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<TreeNode*> > buf(n+2,vector<TreeNode*>());
        buf[0].push_back(NULL);
        buf[1].push_back(new TreeNode(1));
        for(int i=2; i<=n; ++i){
            for(int j=0; j<i; ++j){
                for(int a1=buf[j].size()-1; a1>=0; --a1){
                    for(int a2=buf[i-1-j].size()-1; a2>=0; --a2){
                        TreeNode* head = new TreeNode(j+1);
                        head->left = copyTree(buf[j][a1],0);
                        head->right = copyTree(buf[i-1-j][a2],j+1);
                        buf[i].push_back(head);
                    }
                }
            }
        }
        return buf[n];
    }