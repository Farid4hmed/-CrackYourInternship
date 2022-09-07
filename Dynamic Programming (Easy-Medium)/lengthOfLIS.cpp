class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int longest = 1;
        for(int i=1; i<nums.size(); i++){
            int maxNum = 0;
            for(int j=i-1; j>=0; j--){
                if(nums[j] < nums[i])maxNum = max(maxNum, dp[j]);
            }
            dp[i] = maxNum + 1;
            longest = max(longest, dp[i]);
        }
        return longest;
    }
};
