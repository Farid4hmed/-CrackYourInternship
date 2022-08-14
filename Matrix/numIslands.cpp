void explore(vector<vector<char>>& grid, int i, int j){
        if(grid[i][j] == '1'){
            grid[i][j] = '0';
            if(j!=grid[0].size()-1)explore(grid, i, j+1);//right
            if(i!=grid.size()-1)explore(grid, i+1, j);//down
            if(i!=0)explore(grid, i-1, j);//up
            if(j!=0)explore(grid, i, j-1);//left
        }
    }  
        
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    res += 1;
                explore(grid, i, j);
                }
            }
        }
        return res;
    }
