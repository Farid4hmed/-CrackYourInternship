class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = (x*x) + (y*y);
            pq.push({dist, i});
        }
        vector<vector<int>> ans;
        while(k--){
            vector<int> v;
            v.push_back(points[pq.top().second][0]);
            v.push_back(points[pq.top().second][1]);
            pq.pop();
            ans.push_back(v);
        }
        return ans;
    }
};
