bool isPossible(long long a[], long long b[], int n, long long k) {
        for(int i=0; i<n; i++)if(a[i] + b[i] >= k)return true;
        return false;
    }
