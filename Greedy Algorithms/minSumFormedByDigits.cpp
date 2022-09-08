class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        if(n==0)return 0;
        sort(arr, arr+n);
        long long int num1=0, num2=0;
        for(int i=0; i<n; i++){
            if(i%2==0){
                num1 = num1*10 + arr[i];
            }
            else num2 = num2*10 + arr[i];
        }
        return num1+num2;
    }
};
