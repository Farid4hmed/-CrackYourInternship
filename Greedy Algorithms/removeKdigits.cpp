class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        st.push(num[0]);
        for(int i=1; i<num.length(); i++){
            while(k>0 && !st.empty() && st.top() > num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
            if(st.size() == 1 && num[i] == '0')
                st.pop();
        }
        while(k && !st.empty()){
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans == ""? "0" : ans;
    }
};
