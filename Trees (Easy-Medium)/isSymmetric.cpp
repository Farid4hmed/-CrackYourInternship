class Solution {
public:
    bool isSymmetric(TreeNode* root){ return isMirrorTree(root->left, root->right); }
    
    //return true if left subtree is a mirror of right subtree else false.
    bool isMirrorTree(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL)return true; // if both left && right subtrees are NULL, then they are automatically mirror of themselves
        
        // we traverse recursively to the left and right of both subtrees as soon as we find equal values of root
        if(root!=NULL && subRoot!=NULL && root->val == subRoot->val)
        return (isMirrorTree(root->left, subRoot->right) && isMirrorTree(root->right, subRoot->left));
       
        return false; //this line will only be executed when one of the subtrees is NULL
    }
};
