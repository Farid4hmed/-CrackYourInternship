vector<int> findDuplicates(vector<int>& nums) {
        vector <int> ans;
        for(int i=0; i<nums.size(); i++){
            int idx = abs(nums[i]) - 1;
            if(nums[idx] < 0)ans.push_back(abs(nums[i]));
            nums[idx] = -nums[idx];
        }
        return ans;
    }
