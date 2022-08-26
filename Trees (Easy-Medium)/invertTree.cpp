class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
       if(root == NULL || root->left == NULL && root->right == NULL)return root;
        invertTree(root->left);
        invertTree(root->right);
        //swap
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};
