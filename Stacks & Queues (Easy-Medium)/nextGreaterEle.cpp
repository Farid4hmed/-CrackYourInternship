    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int nextGreater[nums2.size()];
        stack<int> st1;
        st1.push(nums2[nums2.size()-1]);
        nextGreater[nums2.size()-1] = -1;
        for(int i=nums2.size()-2; i>=0; i--){
            if(st1.top() > nums2[i])nextGreater[i] = st1.top();
            else {
                while(!st1.empty() && st1.top() <= nums2[i])st1.pop();
                if(st1.empty())nextGreater[i] = -1;
                else nextGreater[i] = st1.top();
            }
            st1.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums2[j] == nums1[i]){
                    ans.push_back(nextGreater[j]);
                    break;
                }
            }
        }
        return ans;
        
    }
};
