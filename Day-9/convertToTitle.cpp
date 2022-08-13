string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber>0){
        ans += (columnNumber-1)%26 + 'A';
        columnNumber -= 1;
        columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
