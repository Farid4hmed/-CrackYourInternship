class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)return NULL;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != NULL && right != NULL)return root;
        else {
            if(left == NULL && right == NULL){
                if(root->val == p->val)return p;
                else if(root->val == q->val)return q;
                else return NULL;
            }
            else {
                if(left!=NULL){
                    if(root->val == p->val && root->val != left->val || root->val == q->val && root->val != left->val)return root;
                    else return left;
                }
                if(right!=NULL){
                    if(root->val == p->val && root->val != right->val || root->val == q->val && root->val != right->val)return root;
                    else return right;
                }
                }
            }
            return NULL;
        }
};
