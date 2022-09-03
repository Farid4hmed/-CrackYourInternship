class Solution {
    bool dfs(vector<vector<int>> &graph, int node, vector<bool> &thoseTrue, vector<bool> &visited){
        bool curr_ans = true;
        visited[node]=true;
        
        for(int j:graph[node]){
            if(!visited[j])
                curr_ans = curr_ans && dfs(graph, j, thoseTrue, visited);
            else
                curr_ans = curr_ans && thoseTrue[j];
        }
        thoseTrue[node]=curr_ans;
        return curr_ans;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<bool> visited(nodes,false);
        vector<bool> thoseTrue(nodes,false);
        vector<int> ans;
        
        for(int i=0;i<nodes;i++){
            if(visited[i]==false)
                dfs(graph,i,thoseTrue,visited);
        }
        
        for(int i=0;i<nodes;i++)
            if(thoseTrue[i]==true)
                ans.push_back(i);
        return ans;
    }
};
