class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int diff[heights.size()];
        diff[0] = -1;
        for(int i=1; i<heights.size(); i++){
            diff[i] = heights[i] - heights[i-1];
        }
        int i;
        for(i=1; i<heights.size(); i++){
            if(diff[i] <= 0)continue;
            if(ladders == 0){
                pq.push(diff[i]);
                bricks -= pq.top();
                pq.pop();
                if(bricks < 0)break;
             }
            else if(diff[i] <= bricks){
                ladders--;
                pq.push(diff[i]);
            }
            else ladders--;
        }
        return i-1;
    }
};
