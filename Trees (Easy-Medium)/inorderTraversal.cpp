class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
};
