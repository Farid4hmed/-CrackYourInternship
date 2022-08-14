vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>>m;

    for(auto i:strs){
          map<char,int>a;
        for(int j=0;j<i.size();j++)a[i[j]]++;
        m[a].push_back(i);
    }
    vector<vector<string>>ans;
    for(auto i:m)ans.push_back(i.second);
    return ans;
    }
