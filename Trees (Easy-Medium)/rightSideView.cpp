class Solution {
public:
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        recur(root, 0);
        return ans;
    }
    void recur(TreeNode* root, int level){
        if(root == NULL)return;
        if(ans.size() == level)ans.push_back(root->val);
        recur(root->right, level+1);
        recur(root->left, level+1);
    }
};
