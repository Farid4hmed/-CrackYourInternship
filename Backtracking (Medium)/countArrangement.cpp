class Solution {
public:
    int count = 0;
    int countArrangement(int n) {
        vector<int> arr;
        for(int i=1; i<=n; i++)arr.push_back(i);
        permutation(arr, 0, n-1);
        return count;
    }
    void permutation(vector<int>& arr, int low, int high){
        if(low == high){
            if(arr[high]%(high+1)==0 || (high+1)%arr[high]==0)count++;
        }
        for(int i=low; i<=high; i++){
            swap(arr[low], arr[i]);
            if(arr[low]%(low+1)==0 || (low+1)%arr[low]==0)permutation(arr, low+1, high);
            swap(arr[low], arr[i]);
        }
    }
};
