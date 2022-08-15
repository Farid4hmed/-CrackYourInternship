class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeroes = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zeroes++;
            }
            else product *= nums[i];
        }
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                if(zeroes == 1)ans.push_back(product);
                else ans.push_back(0);
            }
            else if(zeroes>0){
                ans.push_back(0);
            }
            else ans.push_back(product/nums[i]);
        }
        return ans;
    }
};
