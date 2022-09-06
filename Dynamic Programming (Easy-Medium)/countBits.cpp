class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        int currBase = 1;
        for(int i=1; i<=n; i++){
             if(ceil(log2(i)) == floor(log2(i))){
                 dp[i] = 1;
                 currBase = i;
             }
            else {
                dp[i] = 1 + dp[i - currBase];
            }
        }
        return dp;
    }
};
