class Solution {
private: 
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;

    void inorder(TreeNode* root){
        if(root == NULL)return;
        
        inorder(root->left);
        
        if(prev!=NULL && root->val < prev->val){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        inorder(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last)swap(first->val, last->val);
        else swap(first->val, middle->val);
    }
};
