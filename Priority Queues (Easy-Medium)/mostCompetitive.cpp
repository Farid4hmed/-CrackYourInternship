class Solution {
public:
    vector<int> mostCompetitive(vector<int>& A, int k) {
        vector<int> stack;
        for (int i = 0; i < A.size(); ++i) {
            while (!stack.empty() && stack.back() > A[i] && stack.size() - 1 + A.size() - i >= k)
                stack.pop_back();
            if (stack.size() < k)
                stack.push_back(A[i]);
        }
        return stack;
    }
};
