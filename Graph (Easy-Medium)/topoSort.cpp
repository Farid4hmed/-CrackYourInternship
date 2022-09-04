class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void topoDFS(int src, vector<int> adj[], vector<int>& vis, stack<int>& st){
	    vis[src] = 1;
	    
	    for(auto x: adj[src]){
	        if(!vis[x])topoDFS(x, adj, vis, st);
	    }
	    st.push(src);
	}
	
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   stack<int> st;
	   vector<int> vis(V, 0);
	   
	   for(int i=0; i<V; i++){
	       if(!vis[i])topoDFS(i, adj, vis, st);
	   }
	   
	   vector<int> ans;
	   while(!st.empty()){
	       ans.push_back(st.top());
	       st.pop();
	   }
	   return ans;
	}
};
