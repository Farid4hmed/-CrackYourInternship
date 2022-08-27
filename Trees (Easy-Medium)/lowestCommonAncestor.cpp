class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int x = root->val;
        TreeNode* curr = root;
        if(p->val>x && q->val>x){
            curr = lowestCommonAncestor(root->right, p, q);
        }
        else if(q->val<x && p->val<x){
            curr = lowestCommonAncestor(root->left, p, q);
        }
        return curr;
        
        
    }
};
