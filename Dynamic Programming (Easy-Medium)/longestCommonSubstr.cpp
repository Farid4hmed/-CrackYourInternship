class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>> dp(n, vector<int>(m, 0));
        if(S1[0] == S2[0])dp[0][0] = 1;
        int longest = 0;
        for(int i=0; i<n; i++)if(S1[i] == S2[0]){dp[i][0] = 1; longest = 1;}
        for(int i=0; i<m; i++)if(S1[0] == S2[i]){dp[0][i] = 1; longest = 1;}
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(S1[i] == S2[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    longest = max(longest, dp[i][j]);
                }
            }
        }
        return longest;
    }
};
