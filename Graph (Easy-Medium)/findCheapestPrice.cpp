class Solution {
public:
    //bellman ford.
    int findCheapestPrice(int n, vector<vector<int>>& a, int src, int sink, int k) {
        
        vector<int> c(n, INT_MAX);
        c[src] = 0;
        
        for(int z=0; z<=k; z++){
            vector<int> C(c);
            for(auto e: a)
                if(c[e[0]]!=INT_MAX)C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
            c = C;
        }
        return c[sink] == INT_MAX ? -1 : c[sink];
    }
};
