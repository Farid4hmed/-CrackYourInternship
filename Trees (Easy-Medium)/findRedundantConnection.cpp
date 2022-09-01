class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int par[edges.size()+1];
        int rank[edges.size()+1];
        for(int i=0; i<=edges.size(); i++){
            par[i] = i;
            rank[i] = 1;
        }
        for(int i=0; i<edges.size(); i++){
            if(Union(edges[i][0], edges[i][1], par, rank) == false){
               return {edges[i][0], edges[i][1]};
            }
        }
        return {};
    }
        
        int find(int n, int par[], int rank[]){
            int p = par[n];
            while(p!=par[p]){
                par[p] = par[par[p]];
                p = par[p];
            }
            return p;
        }
        bool Union(int n1, int n2, int par[], int rank[]){
            int p1 = find(n1, par, rank);
            int p2 = find(n2, par, rank);
            
            if(p1 == p2)return false;
            
            if(rank[p1] > rank[p2]){
                par[p2] = p1;
                rank[p1] += rank[p2];
            }
            else{
                par[p1] = p2;
                rank[p2] += rank[p1];
            }
            return true;
        }
};
