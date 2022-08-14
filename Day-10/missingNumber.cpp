int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        int arrSum = 0;
        for(int i=0; i<n; i++){
            arrSum += nums[i];
            totalSum += i;
        }
        totalSum += n;
        
        return (totalSum - arrSum);
    }
