class Solution {
public:
    int deleteAndEarn(vector<int>& A) {
        unordered_map<int, int> count;
        for(int i=0; i<A.size(); i++){
            count[A[i]]++;
        }
        vector<int> nums;
        for(auto x: count){
            nums.push_back(x.first);
        }
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size());
        
        dp[0] = nums[0] * count[nums[0]];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]+1){
               if(i!=1)dp[i] = max(dp[i-1], dp[i-2] + (nums[i] * count[nums[i]]));
               else dp[i] = max(dp[i-1], nums[i] * count[nums[i]]);
            }
            else dp[i] = dp[i-1] + (nums[i] * count[nums[i]]);
        }
        return dp[nums.size()-1];
    }
};
