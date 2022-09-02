class Solution {
  public:
    // Function to detect cycle in a directed graph.
    vector<int>vis, dfsvis;	// Initialize globally
    // Function to detect cycle in a directed graph.
    bool dfs(int node, vector<int>adj[]){
        vis[node] =1 ; 
        dfsvis[node] = 1;
        
        for(auto &nbr: adj[node]){
            if (!vis[nbr]){
                if (dfs(nbr, adj))
                    return true;
            }
            else if (dfsvis[nbr])
                return true;
        }
        dfsvis[node] = 0; 
        return false; 
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vis.resize(V, 0);
        dfsvis.resize(V, 0); 
        
        for(int i = 0;i < V; i++){
            if (vis[i] == 0)
                if (dfs(i, adj))
                    return true; 
        }
        return false;
    }
};
