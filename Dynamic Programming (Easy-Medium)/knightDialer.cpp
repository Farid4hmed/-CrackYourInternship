typedef long long int ll;
class Solution {
public:
    ll mod = 1e9+7;
    ll solve(int node, vector<vector<int>> &adj, int n,vector<vector<ll>> &dp){
        if(n==0) return 1;
        if(dp[node][n]!=-1) return dp[node][n];
        ll  ans = 0;
        for(int i =0;i<adj[node].size();i++){
            int x = adj[node][i];
            ans = (ans + solve(x, adj, n-1,dp))%mod;
        }
        return dp[node][n] = (ans);
    }
    int knightDialer(int n) {
        vector<vector<int>> adj(10);
        adj[0] = {4,6}, adj[1] = {6,8}, adj[2] = {7,9}, adj[3] = {4,8};
        adj[4] = {0,9,3}, adj[5] = {}, adj[6] = {0,1,7}, adj[7] = {2,6};
        adj[8] = {1,3}, adj[9] = {4,2};
        ll ans = 0;
        vector<vector<ll>> dp(10,vector<ll>(n,-1));
        for(int i =0;i<10;i++){
            ans= (ans + solve(i,adj,n-1,dp))%mod;
            ans=ans%mod;
        }
        return int(ans%mod) ;
        
    }
};
