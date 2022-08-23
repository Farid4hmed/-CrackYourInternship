class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> st;
        int sum = 0;
        int t;
        for (int a : arr) {
            while (!st.empty() && a > st.top()) {
                t = st.top();
                st.pop();
                if (st.empty()) sum += t*a;
                else sum += t*min(st.top(), a);
            }
            st.push(a);
        }
        while (!st.empty()) {
            t = st.top();
            st.pop();
            if (!st.empty()) sum += st.top()*t;
        }
        return sum;
    }
};
