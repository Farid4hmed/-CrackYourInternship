int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1, count;
        
        while(low <=  high)
        {
            int mid = low + (high - low) / 2;
            count = 0;
            for(int i : nums){
                if(i <= mid)
                    ++count;
            }
            if(count <= mid)low = mid + 1;
            else    high = mid - 1;
            
        }
        return low;
    }
