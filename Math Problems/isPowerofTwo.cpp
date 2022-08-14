bool isPowerOfTwo(int n) {
        int countSet = 0;
        while(n > 0){
            if(n & 1 == 1)countSet++;
            n = n>>1;
        }
        if(countSet == 1)return true;
        else return false;
    }
