class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance = 0;
        int i=0;
        int req = 0;
        int j = 0;
        for(int i=0; i<gas.size(); i++){
            balance += gas[i] - cost[i];
            if(balance < 0){
                j = i+1;
                req += balance;
                balance = 0;
            }
        }
        if(balance + req >= 0)return j;
        else return -1;
    }
};
