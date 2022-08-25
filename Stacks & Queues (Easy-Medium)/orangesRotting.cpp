class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int count_fresh = 0;
        for(int i = 0 ; i < rows ; i++) {
            for(int j = 0 ; j < cols ; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) {
                    count_fresh++;
                }
            }
        }
        if(count_fresh == 0) return 0;
        int count = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()) {
            ++count;
            int size = q.size();
            for(int i = 0 ; i < size ; i++) {
                pair<int, int> point = q.front();
                q.pop();
                for(auto dir : dirs) {
                    int x = point.first + dir[0];
                    int y = point.second + dir[1];
                if(x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] == 0 || grid[x][y] == 2) continue;
                    grid[x][y] = 2;
                    q.push({x , y});
                    count_fresh--;
                }
            }
        }
        return count_fresh == 0 ? count-1 : -1;
    }
};
