class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int currMax = INT_MAX;
        int time = 0;
        for(int i=1; i<colors.size(); i++){
            if(colors[i] == colors[i-1]){
               if(currMax == INT_MAX){
                   time += min(neededTime[i], neededTime[i-1]);
                   currMax = max(neededTime[i], neededTime[i-1]);
                   }
                else {
                    time += min(currMax, neededTime[i]);
                    currMax = max(currMax, neededTime[i]);
                }
            }
            else {
                currMax = INT_MAX;
            }
        }
        return time;
    }
};
