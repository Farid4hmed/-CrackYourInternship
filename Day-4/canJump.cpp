bool canJump(vector<int>& nums) {
        int reach = nums.size()-1;
        
        for(int i=nums.size()-1; i>=0; i--){
            if(i+nums[i] >= reach)reach = i;
        }
        if(reach == 0)return true;
        else return false;
    }
