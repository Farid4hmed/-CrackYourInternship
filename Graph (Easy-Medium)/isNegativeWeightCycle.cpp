class Solution {
public:
  //Bellman Ford
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector <int> weight(n, INT_MAX);
	    weight[0] = 0;
	    for(int i=0; i<n-1; i++){
	        vector<int> Copy(weight);
	        for(auto e: edges){
	            if(Copy[e[0]] != INT_MAX)Copy[e[1]] = min(Copy[e[1]], Copy[e[0]] + e[2]);
	        }
	        weight = Copy;
	    }
	    
	    for(int i=0; i<edges.size(); i++){
	        if(weight[edges[i][1]] > weight[edges[i][0]] + edges[i][2])return 1;
	    }
	    return 0;
	}
};
