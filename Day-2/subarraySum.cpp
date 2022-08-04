int subarraySum(vector<int>& nums, int k) {
         int res = 0;
        int currSum = 0;
        int diff;
        unordered_map <int, int> m;
        m[0] = 1;
        for(int n: nums){
            currSum += n;
            diff = currSum - k;
            if(m.find(diff) != m.end()){
                res += m[diff];
            }
            m[currSum]++;
            
            
        }
        return res;
    }
