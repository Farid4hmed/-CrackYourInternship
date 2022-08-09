string longestCommonPrefix(vector<string>& strs) {
        int l = strs.size();
        if(l == 1)return strs[0];
        string ans = "";
        for(int i=0; i<strs[0].size() && i<strs[1].size(); i++){
            if(strs[0][i] == strs[1][i])ans += strs[0][i];
            else break;
        }
        if(l == 2)return ans;
        
        for(int i=2; i<l; i++){
           int x = ans.length();
            while(x--){
                if(strStr(strs[i], ans) != 0)ans = ans.substr(0, x);
                else break;
            }
        }
        return ans;
    }
    int strStr(string haystack, string needle) {
        int nl = needle.length();
        int hl = haystack.length();
        if(nl==0)return 0;
        for(int i=0; i<=hl-nl; i++){
            if(haystack.substr(i, nl) == needle)return i;
        }
        return -1;
    }
