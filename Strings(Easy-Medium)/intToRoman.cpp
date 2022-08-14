string intToRoman(int num) {
        map<int, string> m;
        m[4] = "IV"; m[1] = "I";
        m[9] = "IX"; m[5] = "V";
        m[40] = "XL"; m[10] = "X";
        m[90] = "XC"; m[50] = "L";
        m[400] = "CD";m[100] = "C";
        m[900] = "CM"; m[500] = "D";
        m[1000] = "M";
        
        string roman = "";
        for(auto it=m.rbegin(); it!=m.rend(); it++){
            int count = 0;
        if(num/it->first){
          count = num / it->first;
          while(count--)roman += it->second;
            num = num % it->first;
        }
        
        }
        return roman;
        
    }
