int kthFactor(int n, int k) {
        set<int> s;
        for(int i=1; i*i<=n; i++){
            if(n%i == 0){
                s.insert(i);
                s.insert(n/i);
            }
        }
        
        for(auto x: s){
            k--;
            if(k==0)return x;
        }
        return -1;
    }
