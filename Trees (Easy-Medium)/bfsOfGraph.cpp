class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V);
     visited[0]=1;
     queue<int> q;
     q.push(0);
     vector<int> ans;
     while(!q.empty()){
         int frontNode=q.front();
               ans.push_back(frontNode);
           q.pop();
           for(i:adj[frontNode]){
               if(!visited[i]){
                   visited[i]=1;
                   q.push(i);
               }
           }
     }
    return ans;
    }
};
