class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            if(manager[i] != -1)
                adj[manager[i]].push_back(i);
        }
        queue<int> q;
        map<int, int> m;
        q.push(headID);
        m[headID] = 0;
        
        int maxTime = 0;
        while(!q.empty()){
            int current = q.front();
            int size = adj[current].size();
            
            for(int i=0; i<size; i++){
                q.push(adj[current][i]);
                m[adj[current][i]] = m[current] + informTime[current];
                maxTime = max(maxTime, m[adj[current][i]]);
            }
            q.pop();
        }
        return maxTime;
    }
};
