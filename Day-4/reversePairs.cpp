int mergesort(int l, int r, vector<int>&arr, vector<int>&temp)
    {
        if(l>=r)
        {
            return 0;
        }
        int mid = l+((r-l)/2);
        int ans = mergesort(l, mid, arr, temp);
        ans += mergesort(mid+1, r, arr, temp);
        ans += merge(l, r, arr, temp);
        return ans;
    }
    int merge(int l, int r, vector<int>&arr, vector<int>&temp)
    {
        int mid = l+((r-l)/2);
        int i=l, j=mid+1, k=l;
        int ans=0;
        while(i<=mid && j<=r)
        {
            if(arr[i]/2+max(0,arr[i]%2)<=arr[j])
            {
                i++;
            }
            else{
                ans+=mid-i+1;
                j++;
            }
        }
        i=l;
        j=mid+1;
        while(i<=mid && j<=r)
        {
            if(arr[i]<arr[j])
            {
                temp[k++]=arr[i++];
            }
            else{
                temp[k++]=arr[j++];
            }
        }
        while(i<=mid)
            temp[k++]=arr[i++];
        while(j<=r)
            temp[k++]=arr[j++];
        for(int idx=l; idx<=r; idx++)
            arr[idx]=temp[idx];
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n);
        return mergesort(0, n-1, nums, temp);
    }
