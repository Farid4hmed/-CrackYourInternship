int reverse(int x) {
        bool neg = false;
        if(x<0){
                x = abs(x);
                neg = true;
        }
        long long int mul = 1;
        while(x >= mul*10)mul *= 10;
        long long int rev = 0;
        
        while(x>0){
            
            rev += (x%10) * mul;
            x /= 10;
            mul /= 10;
        }
        if(rev > INT_MAX)return 0;
        else if(neg)return -rev;
        else return rev;
        
    }
