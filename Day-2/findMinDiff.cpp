long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(), a.end());
    long long minDiff = INT_MAX;
    for(int i=0; i<= n-m; i++){
        minDiff = min(minDiff, a[i+(m-1)] - a[i]);
    }
    return minDiff;
    
    } 
