int majorityElement(vector<int>& nums) {
        int currMajor = nums[0];
        int majorCount = 1;
        
        for(int i=1; i<nums.size(); i++){
            if(currMajor == nums[i])majorCount++;
            else majorCount--;
            if(majorCount == 0){
                currMajor = nums[i];
                majorCount++;
            }
        }
        return currMajor;
    }
