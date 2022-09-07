class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int res = 0;
        int j = 0;
        for(int i=0; i<s.size(); i++){
            count[s[i]-'A']++;
            int maxEle = 0;
            int currSize = i-j+1;
            for(int i=0; i<26; i++)maxEle = max(maxEle, count[i]);
            if(currSize - maxEle <= k)res = max(res, currSize);
            else {
                count[s[j]-'A']--;
                j++;
            }
        }
        return res;
    }
};
