class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)return 0;
        int leftDepth=0, rightDepth=0;
        if(root->left != NULL)leftDepth = maxDepth(root->left);
        if(root->right != NULL)rightDepth = maxDepth(root->right);
        return 1 + max(leftDepth, rightDepth);
    }
};
