class Solution {
public:
    int sum = 0;
    void recursion(TreeNode* root){
        if(root->left){
            if(!root->left->left && !root->left->right)sum += root->left->val;
        }
        if(root->left)recursion(root->left);
        if(root->right)recursion(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        recursion(root);
        return sum;
    }
};
