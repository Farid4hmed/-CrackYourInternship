class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26] = {0};
        for(auto x: tasks){
            count[x-'A']++;
        }
        sort(count, count+26);
        int max_val = count[25] - 1;
        int idle_slots = max_val * n;
        
        for(int i=24; i>=0; i--){
            if(count[i] == max_val+1)idle_slots -= count[i]-1;
            else idle_slots -= count[i];
        }
        
        return idle_slots > 0 ? idle_slots+tasks.size() : tasks.size();
    }
};
