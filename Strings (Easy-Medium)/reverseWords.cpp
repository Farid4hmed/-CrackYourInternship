string reverseWords(string s) {
        stack<string> st;
        s += ' ';
        int n = s.length();
        string curr = "";
        for(int i=0; i<n; i++){
            if(s[i] == ' ' && curr != ""){
                st.push(curr);
                curr = "";
            }
            
            else if(s[i] != ' ')curr += s[i];
        }
        string res = "";
        while(!st.empty()){
          res += st.top() + " ";
            st.pop();
        }
        res = res.substr(0, res.length()-1);
        return res;
    }
