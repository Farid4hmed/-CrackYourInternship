class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int countSquares = 0;
        for(int i=0; i<n; i++){if(matrix[i][0] == 1){dp[i][0] = 1; countSquares++;}}
        for(int i=1; i<m; i++){if(matrix[0][i] == 1){dp[0][i] = 1; countSquares++;}}
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 1){
                int diag = dp[i-1][j-1];
                int left = dp[i][j-1];
                int top = dp[i-1][j];
                dp[i][j] += min(diag, min(top, left)) + 1;
                }
                countSquares += dp[i][j];
            }
        }
        return countSquares;
    }
};
