class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void toposort(int node,vector<int>&vis,vector<int>adj[],stack<int>&stk){
    vis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0){
            toposort(it,vis,adj,stk);
        }
    }
    stk.push(node);
}
void revdfs(int node,vector<int>&vis,vector<int>transpose[]){
    vis[node]=1;
    for(auto it:transpose[node]){
        if(vis[it]==0){
            revdfs(it,vis,transpose);
        }
    }
}
   int kosaraju(int V, vector<int> adj[])
   {
       //code here
       stack<int>stk;
       vector<int>vis(V,0);
       for(int i=0;i<V;i++){
           if(vis[i]==0){
               toposort(i,vis,adj,stk);
           }
       }
       vector<int>transpose[V];
       for(int i=0;i<V;i++){
           vis[i]=0;
           for(auto it:adj[i]){
               transpose[it].push_back(i);
           }
       }
       int count=0;
       while(!stk.empty()){
           int node=stk.top();
           stk.pop();
           if(vis[node]==0){
               count++;
               revdfs(node,vis,transpose);
           }
       }
       return count;
   }
};
