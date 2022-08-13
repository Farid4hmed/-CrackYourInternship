string addBinary(string a, string b) {
        int carry = 0;
        int al = a.length();
        int bl = b.length();
        string ans = "";
        int i=al-1, j = bl-1;
        while(i>=0 && j>=0){
            if(a[i]=='1' && b[j]=='1'){
                if(carry==1)ans += '1';
                else ans += '0';
                carry = 1;
            }
            else if(a[i]=='0' && b[j]=='0'){
                if(carry==1)ans += '1';
                else ans+= '0';
                carry = 0;
            }
            
            else{
                if(carry == 1){
                    ans += '0';
                    carry = 1;
                }
                else ans += '1';
            }
            i--; j--;
        }
        
        while(i>=0){
            if(a[i] == '1'){
            if(carry == 1)ans += '0';
            else ans += '1';   
            }
            else if(carry == 1){
                ans += '1'; 
                carry = 0;
            }
            else ans += '0';
            i--;
        }
        while(j>=0){
           if(b[j] == '1'){
            if(carry == 1)ans += '0';
            else ans += '1';   
            }
            else if(carry == 1){
                ans += '1'; 
                carry = 0;
            }
            else ans += '0';
            j--;
        }
        if(carry == 1)ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
   }
