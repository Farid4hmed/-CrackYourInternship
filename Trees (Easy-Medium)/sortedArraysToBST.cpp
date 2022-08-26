class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int m = l + (r-l)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = helper(l, m-1, nums);
        root->right = helper(m+1, r, nums);
        return root;
    }
    
    TreeNode* helper(int l, int r, vector<int>& nums){
        if(l>r)return NULL;
        int m = l + (r-l)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = helper(l, m-1, nums);
        root->right =  helper(m+1, r, nums);
        return root;
        
    }
};
