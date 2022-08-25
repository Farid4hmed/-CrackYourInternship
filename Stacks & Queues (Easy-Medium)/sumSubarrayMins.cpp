class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        long long mod = 1e9 + 7;
        
        vector<int> left_smaller(n, -1);
        
        vector<int> right_smaller(n, n);
        
        stack<int> st;
        
        for(int i = 0; i < n; i++)
        {
            
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
    
           
            if(st.empty())
            {
                left_smaller[i] = -1;
            }
            else
            {
                left_smaller[i] = st.top();
            }
            
            
            st.push(i);
        }
        
        while(!st.empty())
        {
            st.pop();
        }
        
        for(int i = n - 1; i >= 0; i--)
        {
            
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            
            
            if(st.empty())
            {
                right_smaller[i] = n;
            }
            else
            {
                right_smaller[i] = st.top();
            }
            
            st.push(i);
        }
        
        long long sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            
            long long curr = ((right_smaller[i] - i) % mod * (i - left_smaller[i]) % mod * arr[i] % mod) % mod;
            
            sum = (sum % mod + curr % mod) % mod;
        }
        
        return sum;
        
    }
};
