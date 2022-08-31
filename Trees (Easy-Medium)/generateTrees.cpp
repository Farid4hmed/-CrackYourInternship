class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> list;
        
        if(start > end){
            list.push_back(NULL);
            return list;
        }
        if(start == end){
            list.push_back(new TreeNode(start));
            return list;
        }
        
        for(int i=start; i<=end; i++){
            vector<TreeNode*> leftSubtrees = helper(start, i-1);
            vector<TreeNode*> rightSubtrees = helper(i+1, end);
            
            for(auto ltree: leftSubtrees){
                for(auto rtree: rightSubtrees){
                    TreeNode* root = new TreeNode(i);
                    root->left = ltree;
                    root->right = rtree;
                    list.push_back(root);
                }
            }
        }
        return list;
    }
};
