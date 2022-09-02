class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool check(vector<int> adj[],vector<int> &vis,vector<int> &rec,int i,int parent){
        if(vis[i]==0){
            vis[i]=1;
            rec[i]=1;
            for(auto x:adj[i]){
                if(!vis[x]&&check(adj,vis,rec,x,i)){
                    return true;
                }
                else if(rec[x]&&x!=parent){
                    return true;
                }
            }
        }
        rec[i]=0;
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> rec(V,0);
        int parent=-1;
        for(int i=0;i<V;i++){
            if(!vis[i]&&check(adj,vis,rec,i,parent)){
                return true;
            }
        }
        return false;
    }
};
