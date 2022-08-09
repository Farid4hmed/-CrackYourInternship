bool isValid(string s) {
        stack<char> st;
        int l = s.length();
        for(int i=0; i<l; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')st.push(s[i]);
            else if(!st.empty()){
                if(s[i] == ')' && st.top() != '(')return false;
                else if(s[i] == '}' && st.top() != '{')return false;
                else if(s[i] == ']' && st.top() != '[')return false;
                else st.pop();
            }
            else return false;
        }
        return st.empty();
    }
