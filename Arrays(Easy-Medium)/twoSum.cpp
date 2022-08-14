vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[(target - nums[i])] = i;
        }
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(m.find(nums[i]) != m.end() && m[nums[i]] != i){
                ans.push_back(i);
                ans.push_back(m[nums[i]]);
                break;
            }
        }
        return ans;
    }
