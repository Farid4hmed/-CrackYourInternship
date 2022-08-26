class Solution {
public:
    int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        int leftmax = maxDist(root->left);
        int rightmax = maxDist(root->right);
        return max(maxDiameter, leftmax+rightmax);
    }
    
    int maxDist(TreeNode* root){
        if(root == NULL)return 0;
        int leftmax = 0;
        int rightmax = 0;
        leftmax = maxDist(root->left);
        rightmax = maxDist(root->right);
        maxDiameter = max(maxDiameter, leftmax+rightmax);
        return 1 + max(leftmax, rightmax);
    }
};
