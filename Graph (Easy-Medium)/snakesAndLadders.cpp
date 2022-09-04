class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        queue<int>q;
        int n=board.size();
        vector<int>b;
        int count=1;
        vector<bool>visit(n*n+1,false);
        int k=0;
        
        b.push_back(0); 
        for(int i=n-1;i>=0;i--){
            if(k%2==0){
                for(int j=0;j<n;j++){
                    b.push_back(board[i][j]);
                }
            }
            else{
                for(int j=n-1;j>=0;j--){
                    b.push_back(board[i][j]);
                }
            }
            k++;
        }
        
        q.push(1);
        visit[1]=true;
        
        
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                int num=q.front();
                q.pop();
                if(num==n*n)return count;
                
                for(int j=1;j<=6;j++){
                    int x=num+j;
                    if(b[x]!=-1)
                        x=b[x];
                    if(x==n*n) return count;
                    if(visit[x]) continue;
                    visit[x]=true;
                    q.push(x);
                }
            }
            count++;
        }
        return -1;
        
    }
};
