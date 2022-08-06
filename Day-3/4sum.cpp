vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();  
        sort(nums.begin() , nums.end());
        vector<vector<int>> res;  
        set<vector<int>> temp;
		
        for(int i = 0 ; i < n; i++){
		    for(int j = i + 1; j < n ; j++){
			    long long new_target  =  (long long)target - nums[i] - nums[j];
                int a = j+1;
                int b = n-1;
                
                while(a < b){
				    long long sum = nums[a] + nums[b];
                    if(sum > new_target) b--;
                    else if(sum < new_target) a++;
                    else{
                        temp.insert({nums[i] , nums[j] , nums[a] , nums[b]});
                        a++;
                        b--;
                    }
                }
            }
        }
		
        for(auto i : temp){
            res.push_back(i);
        }
		
        return res;
    }
