class Solution {
public:

    bool cyclic(int src, vector<int>&vis, vector<int>&rec, vector<int>adj[]){
	    
	    vis[src] = 1;
	    
	    rec[src] = 1;
	    
	    for(auto it : adj[src]){
	        
	        if(!vis[it]){
	            
	            if(cyclic(it, vis, rec, adj)) return true;
	            
	        }else if(rec[it]) return true;
	    }
	    
	    rec[src] = 0;
	    
	    return false;
	}
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    int edges = prerequisites.size();
	     vector<int> vis(N, 0);
	     vector<int> rec(N, 0);
	    for(int i=0; i<edges; i++){
	        adj[prerequisites[i].second].push_back(prerequisites[i].first);
	    }
	    for(int i=0; i<N; i++){
	        if(cyclic(i, vis, rec, adj))return false;
	    }
	    return true;
	}
};
