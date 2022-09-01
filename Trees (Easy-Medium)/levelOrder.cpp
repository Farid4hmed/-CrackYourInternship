class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> v;
            int size = q.size();
            for(int i=0; i<size; i++){
                if(q.front()->left)q.push(q.front()->left);
                if(q.front()->right)q.push(q.front()->right);
                v.push_back(q.front()->val);
                q.pop();
            }
            ans.push_back(v);
        }
        return ans;
    }
};
