class Solution {
public:
    
    void dfs(int i,int j,vector<vector<char>> &board,bool &f,vector<vector<int>> &vis,int r,int c,vector<pair<int,int>> &v){
        if(i<0 or j<0 or j>=c or i>=r) return;
        if(vis[i][j] or board[i][j]=='X') return;
        if(i==0 or i==r-1 or j==0 or j==c-1){
            f=1;
            return;
        }
        vis[i][j]=1;
        v.push_back({i,j});
        dfs(i+1,j,board,f,vis,r,c,v);
        dfs(i-1,j,board,f,vis,r,c,v);
        dfs(i,j+1,board,f,vis,r,c,v);
        dfs(i,j-1,board,f,vis,r,c,v);
    }
    
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        queue<pair<int,int>> q;
        for(int i=1;i<r-1;i++){
            for(int j=1;j<c-1;j++){
                if(board[i][j]=='O'){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> vis(r,vector<int> (c,0));   
        while(!q.empty()){
            bool f=0;
            pair<int,int> t=q.front();
            q.pop();
            int x=t.first;
            int y=t.second;
            vector<pair<int,int>> v;
            if(vis[x][y]) continue;
            else{
                dfs(x,y,board,f,vis,r,c,v);
            }
            if(!f){
                for(auto l:v){
                    board[l.first][l.second]='X';
                }
            }
        }
    }
};
