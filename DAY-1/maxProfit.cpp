int maxProfit(vector<int>& prices) {  
        int n = prices.size();
        
        if(n==1)return 0;
        if(n==2)return max((prices[1] - prices[0]), 0);
        
        int rightMax[n];
        rightMax[n-1] = prices[n-1];
        rightMax[n-2] = prices[n-1];
        for(int i=n-3; i>=0; i--){
            if(prices[i+1] > rightMax[i+1]){
                rightMax[i] = prices[i+1];
            }
            else rightMax[i] = rightMax[i+1];
        }
        
        int maxProf = 0;
        for(int i=0; i<prices.size()-1; i++){
            maxProf = max(maxProf, (rightMax[i] - prices[i]));
        }
        return maxProf;
    }
