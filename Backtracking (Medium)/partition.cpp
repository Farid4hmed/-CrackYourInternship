class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        backtrack(s, 0, s.length(), partition);
        return ans;
    }
    
    void backtrack(string s, int low, int high, vector<string>& partition){
        if(low == high){
            ans.push_back(partition);
            return;
        }
        
        for(int i=low; i<high; i++){
            string currString = s.substr(low, i-low+1);
            if(isPalindrome(currString)){
                partition.push_back(currString);
                backtrack(s, i+1, high, partition);
                partition.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s){
        int low = 0;
        int high = s.length()-1;
        while(low<=high){
            if(s[low] != s[high])return false;
            low++;
            high--;
        }
        return true;
    }
};
