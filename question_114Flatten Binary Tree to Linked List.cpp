//吐血……后续遍历得到链表……亏我看了半天是怎么回事……
    TreeNode* merge(TreeNode* begin, TreeNode* begin_right){
        if(begin == NULL)
            return begin_right;
        begin->right = merge(begin->left, merge(begin->right, begin_right));
        begin->left = NULL;
        return begin;
    }
    
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        merge(root,NULL);
    }

//上面代码可读性比较差，改成下面的后，应该很多人就好理解了，上面的其实可以让你理解函数的参数的运算方式~
//看函数参数，应该从后往前看。
    TreeNode* flatten(TreeNode* root, TreeNode* next){
        if(root == NULL)
            return next;
        next=flatten(root->right, next);
        next=flatten(root->left, next);
        root->right = next;
        root->left = NULL;
        return root;
    }

    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        flatten(root,NULL);
    }