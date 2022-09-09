class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> vis(n, 0);
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target, vis, 0);
        return ans;
    }
    
    void backtrack(vector<int>& candidates,int origin, int target, vector<int>& vis, int sum){
        if(sum > target)return;
        
        if(sum == target){
            vector<int> combination;
        for(int i=0; i<vis.size(); i++)
            if(vis[i]==1)combination.push_back(candidates[i]);
            ans.push_back(combination);
            return;
        }
        
        for(int i=origin; i<candidates.size(); i++){
         if(i!=0 && candidates[i]==candidates[i-1] && vis[i-1]==0)continue;
         if(vis[i] == 0){
            vis[i] = 1;
            backtrack(candidates, i+1, target, vis, sum + candidates[i]);
            vis[i] = 0;
         }
       }
        
    }
};
