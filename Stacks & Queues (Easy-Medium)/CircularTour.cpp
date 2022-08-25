class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int rear = 0;
        int front = 0;
        int balance = 0;
        int rearBalance=0;
        int surplus = 0;
       for(int i=0; i<n; i++){
           if(balance < 0){
               rearBalance += balance;
               balance = 0;
               rear = i;
               front = i;
           }
            surplus += gas[i] - cost[i];
            balance += gas[i] - cost[i];
       }
        if(surplus < 0)return -1;
       else if(rearBalance <= balance)return rear;
        return -1;
    }
};
