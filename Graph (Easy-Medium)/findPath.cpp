class Solution{
    public:
    vector<string>ans;
   void path(int i,int j,int n,string s,vector<vector<int>> &arr)
   {
        if(i<0 || i>=n || j<0 ||j>=n)
          return;
      if(arr[i][j]==0 || arr[i][j]==-1)
          return;
      if(i==n-1 && j==n-1)
          ans.push_back(s);
      arr[i][j]=-1;
      path(i-1,j,n,s+"U",arr);//uppper
      path(i+1,j,n,s+"D",arr);//lower
      path(i,j-1,n,s+"L",arr);//left
      path(i,j+1,n,s+"R",arr);//right
      arr[i][j]=1;
   }
   vector<string> findPath(vector<vector<int>> &m, int n) {
       // Your code goes here
       path(0,0,n,"",m);
       return ans;
   }
};
