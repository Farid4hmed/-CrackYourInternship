class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto a : nums)sum += a;
        
        if (sum % 2)return false;
        
        sum /= 2;
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        
        for (auto a : nums) {
            for (int i = sum; i >= a; i--) {
                dp[i] = dp[i] || dp[i-a];
            } 
        }
        return dp[sum];
    }
};
