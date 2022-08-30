class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int leftHeight = 0, rightHeight = 0;
        if(root->left)leftHeight = heightOfSubtree(root->left);
        if(root->right)rightHeight = heightOfSubtree(root->right);
        if(abs(leftHeight - rightHeight) > 1)return false;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(!left || !right)return false;
        return true;
    }
    
    int heightOfSubtree(TreeNode* root){
        if(!root)return 0;
        return max(heightOfSubtree(root->left), heightOfSubtree(root->right)) + 1;
    }
};
