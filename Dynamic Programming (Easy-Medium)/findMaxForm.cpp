class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<vector<vector<int>>> dp(l+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        
        for(int i=1;i<=l;i++)
        {
            string s = strs[i-1];
            int ones = count(s.begin(), s.end(), '1');
            int zeros = s.size()-ones;
            
            for (int j=0;j<=m;j++)
            {
                for (int k=0;k<=n;k++)
                {
                    if (j>=zeros && k>=ones)
                        dp[i][j][k] = max(dp[i-1][j][k], 1 + dp[i-1][j-zeros][k-ones] );
                    else
                        dp[i][j][k] = dp[i-1][j][k];
                    
                }//k
            }//j
        }//i
        
        return dp[l][m][n];
    }
};
