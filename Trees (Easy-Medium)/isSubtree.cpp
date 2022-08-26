class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL)return true;
        if(root == NULL)return false;
        
        if(isSameTree(root, subRoot))return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }
    
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL)return true;
        
        if(root!=NULL && subRoot!=NULL && root->val == subRoot->val)
    return (isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right));
        return false;
    }
};
