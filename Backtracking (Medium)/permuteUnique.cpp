class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        permutation(nums, 0, nums.size()-1);
        return ans;
    }
    
    void permutation(vector<int> nums, int low, int high){
        if(low == high){
            ans.push_back(nums);
            return;
        }
        
        for(int i=low; i<=high; i++){
            if(i!=low && nums[low]==nums[i])continue;
                swap(nums[low], nums[i]);
                permutation(nums, low+1, high);
        }
    }
};
