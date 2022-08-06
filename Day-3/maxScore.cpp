int maxScore(vector<int>& cardPoints, int k) {
        int total_sum = 0;
        int n = cardPoints.size();
        int currSum = 0;
        for(int i=0; i<n; i++){
            total_sum += cardPoints[i];
            if(i<n-k)currSum += cardPoints[i];
        }
        int minSum = currSum;
        for(int i=0; i+n-k<n; i++){
        currSum = currSum - cardPoints[i] + cardPoints[i + n-k];
        minSum = min(minSum, currSum);
        }
        return (total_sum - minSum);
    }
