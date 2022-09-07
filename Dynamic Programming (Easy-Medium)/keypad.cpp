class Solution{
    public:
	long long solve(int node, vector<vector<int>> &adj, int n,vector<vector<long long>> &dp){
        if(n==0) return 1;
        if(dp[node][n]!=-1) return dp[node][n];
        long long  ans = 0;
        for(int i =0;i<adj[node].size();i++){
            int x = adj[node][i];
            ans = ans + solve(x, adj, n-1,dp);
        }
        return dp[node][n] = (ans);
    }
	long long getCount(int n)
	{
		// Your code goes here
		vector<vector<int>> adj(10);
        adj[0] = {0, 8}, adj[1] = {1, 2, 4}, adj[2] = {1, 2, 3, 5}, adj[3] = {2, 3, 6};
        adj[4] = {1, 4, 5, 7}, adj[5] = {2, 4, 5, 6, 8}, adj[6] = {3, 5, 6, 9}, adj[7] = {4, 7, 8};
        adj[8] = {0, 5, 7, 8, 9}, adj[9] = {6, 8, 9};
        long long ans = 0;
        vector<vector<long long>> dp(10,vector<long long>(n,-1));
        for(int i =0;i<10;i++){
            ans= ans + solve(i,adj,n-1,dp);
        }
        return ans ;
	}
};
