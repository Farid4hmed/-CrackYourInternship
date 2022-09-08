class Solution {
public:
    int minDeletions(string s) {
        int count[26] = {0};
        for(char ch: s){
            count[ch - 'a']++;
        }
        vector<int> arr;
        for(int i=0; i<26; i++)if(count[i] != 0)arr.push_back(count[i]);
        
        sort(arr.begin(), arr.end());
        unordered_map<int, int> m;
        for(int i=0; i<arr.size(); i++)m[arr[i]]++;
        int delCount = 0;
        for(int i=arr.size()-1; i>0; i--){
            if(arr[i] == arr[i-1]){
                arr[i]--;
                delCount++;
                while(m.find(arr[i]) != m.end()){
                    arr[i]--;
                    delCount++;
                }
                if(arr[i] > 0)m[arr[i]]++;
            }
        }
        return delCount;
    }  
};
