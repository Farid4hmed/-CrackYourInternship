//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  bool isSafe(int x,int y,vector<vector<int>>& vis,int n){
        if((x>=0 && x<n) && (y>=0 && y<n) && vis[x][y]==0){
          return true;
      }
      return false;
   }
   public:
int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
{
    vector<vector<int>> vis(n,vector<int>(n,0));
    int x=KnightPos[0]-1;
    int y=KnightPos[1]-1;
    
    int tx=TargetPos[0]-1;
    int ty=TargetPos[1]-1;
    
    if(x==tx&&y==ty)
    return 0;
    
       int dx[] = {2,2,-2,-2,1,-1,1,-1};
       int dy[] = {1,-1,1,-1,2,2,-2,-2};
       
       queue<pair<pair<int,int>,int>> q;
       q.push({{x,y},0});
       vis[x][y]=1;
       
       while(!q.empty()){
           auto top=q.front();
           q.pop();
           
           int nx=top.first.first;
           int ny=top.first.second;
           int dis=top.second;
           
           for(int i=0;i<8;i++){
               int x=nx+dx[i];
               int y=ny+dy[i];
               
               if(x==tx&&y==ty)
               return dis+1;
               
               if(isSafe(x,y,vis,n)){
                   vis[x][y]=1;
                   q.push({{x,y},dis+1});
               }
           }
       }
       return -1;
}
};
