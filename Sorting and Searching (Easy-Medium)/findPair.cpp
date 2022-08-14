bool findPair(int arr[], int size, int n){
    unordered_map<int, int> m;
    for(int i=0; i<size; i++){
        m[n+arr[i]]++;
    }
    for(int i=0; i<size; i++){
        if(m.find(arr[i]) != m.end()){
            if(n==0){
                if(m[arr[i]] > 1)return true;
            }
            else return true;
        }
    }
    return false;
}
