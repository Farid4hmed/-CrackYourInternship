class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int count = 0;
        if(m==1 && n==1)return 1;
        if(m!=1)count += countPaths(1, 0, m, n, dp);
        if(n!=1)count += countPaths(0, 1, m, n, dp);
        return count;
    }
    
    int countPaths(int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i == m-1 && j == n-1)return 1;
        if(dp[i][j] != -1)return dp[i][j];
        int count = 0;
        if(i!=m-1)count += countPaths(i+1, j, m, n, dp);
        if(j!=n-1)count += countPaths(i, j+1, m, n, dp);
        dp[i][j] = count;
        return count;
    }
};
