bool validPalindrome(string s) {
        int mistakes = 1;
        int l = 0;
        int r = s.length()-1;
        while(l<r){
            if(s[l] == s[r]){ l++; r--; }
            else{
                    int l1=l, r1=r-1, l2=l+1, r2=r;
                    while(l1<r1){
                        if(s[l1] == s[r1]){ l1++; r1--;}
                        else break;
                    }
                    if(l1>=r1)return true;
                    while(l2<r2){
                        if(s[l2] == s[r2]){l2++; r2--;}
                        else break;
                    }
                    if(l2>=r2)return true;
                    return false;
                }
            }
        return true;
    }
