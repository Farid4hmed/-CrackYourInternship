class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        for(int i=0; i<n; i++){
            int correctpos = arr[i] - 1;
            while(arr[i]>=1 && arr[i]<=n && arr[i] != arr[correctpos]){
                swap(arr[i], arr[correctpos]);
                correctpos = arr[i]-1;
            }
        }
        for(int i=0; i<n; i++){
            if(i+1 != arr[i])return i+1;
        }
        return n+1;
    } 
};
