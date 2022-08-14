int minMoves(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int minNum = INT_MAX;
        for(int i=0; i<n; i++){
            minNum = min(minNum, nums[i]);
        }
        for(int i=0; i<n; i++){
            res += nums[i] - minNum;
        }
        return res;
    }
