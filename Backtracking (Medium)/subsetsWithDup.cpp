class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        backtrack(subset, nums, 0);
        return ans;
    }
    
    void backtrack(vector<int>& subset, vector<int> nums, int idx){
        if(idx == nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[idx]);
        backtrack(subset, nums, idx+1);
        subset.pop_back();
        idx++;
        while(idx<nums.size() && nums[idx]==nums[idx-1])idx++;
        backtrack(subset, nums, idx);
        
    }
};
