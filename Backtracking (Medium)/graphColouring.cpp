class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
     bool solve(int node, int colour[], int m , int N, bool graph[101][101]){
        if(node == N) return true;
        
        for(int i=1; i<=m; i++)
        {
            if(issafe(node, colour, graph, N, i))
            {
                colour[node] = i;
                
                if(solve(node+1, colour, m, N, graph) == true)
                {
                    return true;
                }
                
                colour[node] = 0;//Back-tracking
            }
            
        }
        
        return false;
    }
    bool issafe(int node, int colour[], bool graph[101][101], int n, int col)
    {
        for(int i=0; i<n; i++)
        {
            if(i != node && graph[i][node] == 1 && colour[i] == col)
            {
                return false;
            }
        }
        
        return true;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n] = {0};
      if (solve(0, color, m, n, graph) == true){
          return true;
      }
      return false;
        
    }
};
