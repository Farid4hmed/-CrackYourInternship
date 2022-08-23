class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> st;
        int l = S.length();
        for(int i=0; i<l; i++){
            if(S[i] == '*'){
               int num2 = (int)st.top();
               st.pop();
               int num1 = (int)st.top();
               st.pop();
               st.push(num1*num2);
            }
            else if(S[i] == '/'){
               int num2 = st.top();
               st.pop();
               int num1 = st.top();
               st.pop();
               st.push(num1 / num2);
            }
            else if(S[i] == '+'){
               int num2 = st.top();
               st.pop();
               int num1 = st.top();
               st.pop();
               st.push(num1 + num2);
            }
            else if(S[i] == '-'){
                int num2 = st.top();
               st.pop();
               int num1 = st.top();
               st.pop();
               st.push(num1 - num2);
            }
            else {
                st.push(S[i] - '0');
            }
        }
        return st.top();
    }
};
