class Solution {
public:
    int preidx=0,postidx=0;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post)
    {
        TreeNode* root=new TreeNode(pre[preidx++]);
        if(root->val!=post[postidx])
            root->left=constructFromPrePost(pre,post);
        if(root->val!=post[postidx])
            root->right=constructFromPrePost(pre,post);
        postidx++;
        return root;
    }
};
