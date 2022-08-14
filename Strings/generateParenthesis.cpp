void backtrack(int open,int closed ,vector<string> &res ,string s ,int n){
        if(open == n && closed == n){
            res.push_back(s);
            return;
        }
        if(open < n)backtrack(open+1, closed, res, s+"(", n);
        if(closed < open)backtrack(open, closed+1, res, s+")", n);
    }
    vector<string> generateParenthesis(int n) {
        int open=0, closed=0;
        vector<string> res;
        string s = "";
        backtrack(open, closed, res, s, n);
        return res;
    }
