class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        backtrack(n, k-1, curr, 1);
        return ans;
    }
        void backtrack(int n, int k, vector<int>& curr, int origin){
            
            for(int i=origin; i<=n; i++){
                curr.push_back(i);
                if(k==0)ans.push_back(curr);
                else backtrack(n, k-1, curr, i+1);
                curr.pop_back();
            }
        }
};
