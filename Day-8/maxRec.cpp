class Solution {
    
    vector<int>findPrev(vector<int>&vec){
        vector<int>ans(vec.size());
        stack<int>stk;
        stk.push(-1);
        for(int i=0;i<vec.size();i++){
            int x=vec[i];
            while(stk.top()!=-1 && (vec[stk.top()])>=x)
                stk.pop();
            ans[i]=stk.top();
            stk.push(i);
        }
        return ans;
    }
    
    vector<int>findNext(vector<int>&vec){
        vector<int>ans(vec.size());
        stack<int>stk;
        stk.push(-1);
        for(int i=vec.size()-1;i>=0;i--){
            int x=vec[i];
            while(stk.top()!=-1 && (vec[stk.top()])>=x)stk.pop();
            ans[i]=stk.top();
            stk.push(i);
        }
        return ans;
    }
    
    int findHisto(vector<int>&vec){
        vector<int>prevSmall(vec.size());
        prevSmall = findPrev(vec);
        vector<int>nextSmall(vec.size());
        nextSmall= findNext(vec);
        int ans{};
        
        for(int i=0;i<vec.size();i++){
            int length=vec[i];
            if(nextSmall[i]==-1)nextSmall[i]=vec.size();
            int width = nextSmall[i]-prevSmall[i]-1;
            
            int area=length*width;
            ans=max(area,ans);
        }
        return ans;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans{};
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>vals(row,vector<int>(col,0));
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(matrix[i][j]=='1')vals[i][j]=1;
            
        for(int i=0;i<row;i++){
            if(i==0)
                    ans=findHisto(vals[i]);
            else{    
                for(int j=0;j<col;j++){
                    if((vals[i][j])){
                        vals[i][j]+=vals[i-1][j];
                    }
                 }
                ans=max(ans,findHisto(vals[i]));
               }
             }
        return ans;
    }
};
