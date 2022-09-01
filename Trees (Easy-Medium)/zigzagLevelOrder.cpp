class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)return {};
        vector<vector<int>> ans;
        queue<TreeNode*> dq;
        dq.push(root);
        bool odd = true;
        while(!dq.empty()){
            int size = dq.size();
            vector<int> v(size);
            for(int i=0; i<size; i++){
                TreeNode* temp = dq.front();
                dq.pop();
                int index = odd ? i : size - i - 1;
                v[index] = temp->val;
                if(temp->left)dq.push(temp->left);
                if(temp->right)dq.push(temp->right);
            }
            ans.push_back(v);
            if(odd == false)odd = true;
            else odd = false;
        }
        return ans;
    }
};
