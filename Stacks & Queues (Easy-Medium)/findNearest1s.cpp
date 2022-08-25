class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> dist(n, vector<int>(m, 0));
	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    queue<pair<pair<int, int>, int>> q;
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j] == 1){
	                dist[i][j] = 0;
	                vis[i][j] = 1;
	                q.push(make_pair(make_pair(i, j), 0));
	            }
	        }
	    }
	    
	    while(!q.empty()){
	       int i = q.front().first.first;
	       int j = q.front().first.second;
	       
	       if(i!=0 && vis[i-1][j] != 1){                   
	           dist[i-1][j] = q.front().second+1; 
	           vis[i-1][j] = 1;
	          q.push(make_pair(make_pair(i-1, j), q.front().second+1));
	       }
	       if(i!=n-1 && vis[i+1][j] != 1){
	           dist[i+1][j] = dist[i][j] + 1;
	           vis[i+1][j] = 1;
	           q.push(make_pair(make_pair(i+1, j), q.front().second+1));
	       }
	       if(j!=0 && vis[i][j-1] != 1){
	           dist[i][j-1] = dist[i][j] + 1;
	           vis[i][j-1] = 1;
	           q.push(make_pair(make_pair(i, j-1), q.front().second+1));
	       }
	       if(j!=m-1 && vis[i][j+1] != 1){
	           dist[i][j+1] = dist[i][j] + 1;
	           vis[i][j+1] = 1;
	           q.push(make_pair(make_pair(i, j+1), q.front().second+1));
	       }
	       q.pop();
	    }
	    return dist;
	    
	    
	}
};
