string simplifyPath(string path) {
       stack<string> st;
       string curr = "";
        path += '/';
        int n = path.size();
        for(int i=0; i<n; i++){
            if(path[i] == '/'){
                if(curr == ".."){
                    if(!st.empty())st.pop();
                }
                else if(curr != "" && curr != "."){
                    st.push(curr);
                }
                curr = "";
            }
            else curr += path[i];
        }
        string res = "";
        while(!st.empty()){
        res = "/" + st.top() + res;
        st.pop();
       }
        if(res.size() == 0)return "/";
        return res;
    }
