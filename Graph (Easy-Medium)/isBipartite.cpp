class Solution {
public:
    void dfsCheck(int node,vector<int>&color,vector<int>adj[],bool& ans)
   {
     
       for(auto x:adj[node]){
           if(color[x]==-1){
              color[x]=1-color[node];
              dfsCheck(x,color,adj,ans);
           }
           else if(color[x]==color[node]){
               ans=false;
               return;
           }
       }
   }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>color(V,-1);
	    bool ans=true;
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            color[i]=0;
	            dfsCheck(i,color,adj,ans);
	            if(!ans){
	                return false;
	            }
	        }
	    }
	    return true;
	}
};
