class NumArray {
public:
    vector<int> tree;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        tree.resize(4*n);
        constructST(nums, tree, 0, n-1, 0);
    }
    int constructST(vector<int>& nums, vector<int>& tree, int ss, int se, int si){
        if(ss == se){
            tree[si] = nums[ss];
            return tree[si];
        }
        int mid = (ss+se)/2;
    tree[si] = constructST(nums, tree, ss, mid, 2*si+1)
        + constructST(nums, tree, mid+1, se, 2*si+2);
        return tree[si];
    }
    int sumRangeREC(int qs, int qe, int ss, int se, int si){
        if(se<qs || ss>qe)return 0;
        if(qs<=ss && qe>=se)return tree[si];
        int mid = (ss+se)/2;
        return sumRangeREC(qs, qe, ss, mid, 2*si+1) + sumRangeREC(qs, qe, mid+1, se, 2*si+2);
    }
    int sumRange(int left, int right) {
        int n = tree.size()/4;
        return sumRangeREC(left, right, 0, n-1, 0);
    }
};
