class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        partialInorder(root);
    }
    
    int next() {
        TreeNode* top = s.top();
        s.pop();
        partialInorder(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
    void partialInorder(TreeNode* root){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }
};
