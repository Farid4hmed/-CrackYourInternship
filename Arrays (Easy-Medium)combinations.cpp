vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int>comb;
        backtrack(1, res, comb, k, n);
        return res;
    }
    
void backtrack(int start, vector<vector<int>>&res, vector<int>&comb,int k, int n){
        if(comb.size() == k){
            res.push_back(comb);
            return;
        }
        
        for(int i=start; i<=n; i++){
            comb.push_back(i);
            backtrack(i+1, res, comb, k, n);
            comb.pop_back();
        }
        
    
    }
