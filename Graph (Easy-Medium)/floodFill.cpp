class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        fill(image, sr, sc, color, vis);
        return image;
    }
    void fill(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<bool>>& vis){
        int n = image.size();
        int m = image[0].size();
        vis[sr][sc] = true;
       if(sr!=0 && !vis[sr-1][sc] && image[sr-1][sc] == image[sr][sc])fill(image, sr-1, sc, color, vis);
       if(sr!=n-1 && !vis[sr+1][sc] && image[sr+1][sc] == image[sr][sc])fill(image, sr+1, sc, color, vis);
       if(sc!=0 && !vis[sr][sc-1] && image[sr][sc-1] == image[sr][sc])fill(image, sr, sc-1, color, vis);
       if(sc!=m-1 && !vis[sr][sc+1] && image[sr][sc+1] == image[sr][sc])fill(image, sr, sc+1, color, vis);
       image[sr][sc] = color;
    }
    
   
};
