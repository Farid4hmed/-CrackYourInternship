int subarraysDivByK(vector<int>& nums, int k) {
        int res = 0;
        int currSum = 0;
        int rem;
        unordered_map <int, int> m;
        m[0] = 1;
        for(int n: nums){
            currSum += n;
            rem = currSum%k;
            if(rem<0) rem += k;
            if(m.find(rem) != m.end()){
                res += m[rem];
                m[rem]++;
            }
            else m[rem] = 1;
            
            
        }
        return res;
    }
