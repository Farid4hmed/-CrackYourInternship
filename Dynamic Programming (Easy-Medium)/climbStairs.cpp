class Solution {
public:
    
    int climbStairs(int n) {
        int dp[n+1];
        for(int i=0; i<=n; i++)dp[i] = -1;
        if(n==0 || n==1)return 1;
        dp[0] = 1;
        dp[1] = 1;
        return countWays(n, dp);
    }
    
    int countWays(int n, int dp[]){
        if(n==0)return 1;
        else if(n<0)return 0;
        int ways = 0;
        int oneJump, twoJump;
        if(dp[n-1] != -1)oneJump = dp[n-1];
        else {
            oneJump = countWays(n-1, dp);
            dp[n-1] = oneJump;
        }
        if(dp[n-2] != -1)twoJump = dp[n-2];
        else {
            twoJump = countWays(n-2, dp);
            dp[n-2] = twoJump;
        }
        ways += oneJump + twoJump;
        return ways;
    }
};
