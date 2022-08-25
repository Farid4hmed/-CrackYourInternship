class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(int i=0; i<s.size(); i++){
            if(!st.empty() && st.top().first == s[i]){
                st.top().second++;
            }
            else st.push({s[i], 1});
            
            if(!st.empty() && st.top().second == k)st.pop();
        }
        string res = "";
        while(!st.empty()){
            while(st.top().second--)res += st.top().first;
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};
