class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int currSum = 0;
        return findSum(root, currSum, targetSum);
    }
    bool findSum(TreeNode* root, int currSum, int targetSum){
        if(root == NULL)return false;
        if(root->left == NULL && root->right == NULL){
            if(currSum+root->val == targetSum)return true;
        }
        return (findSum(root->left, currSum+root->val, targetSum) ||
        findSum(root->right, currSum+root->val, targetSum));
        }
};
