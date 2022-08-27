class Solution {
public:
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = to_string(root->val);
        findAllPaths(root, s, ans);
        return ans;
    }
    
    void findAllPaths(TreeNode* root, string s, vector<string>& ans){
    if(root->left == NULL && root->right == NULL){
    ans.push_back(s);
    return;
    }
    if(root->left != NULL)findAllPaths(root->left, s+"->"+to_string(root->left->val), ans);
    if(root->right != NULL)findAllPaths(root->right, s+"->"+to_string(root->right->val), ans);
    }
};
