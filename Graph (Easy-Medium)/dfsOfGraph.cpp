class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> v;
    void dfs(int src, vector<int>&vis, vector<int> g[]){
        vis[src] = 1;
        v.push_back(src);
        for(auto x: g[src]){
            if(!vis[x]){
                dfs(x, vis, g);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        dfs(0, vis, adj);
        return v;
        
    }
};
