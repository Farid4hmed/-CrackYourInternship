class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for(int i=0; i<n; i++){
            if(tokens[i] == "*"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2*num1);
            }
            else if(tokens[i] == "/"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2/num1);
            }
            else if(tokens[i] == "+"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2+num1);
            }
            else if(tokens[i] == "-"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2-num1);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
