class Solution{
    struct TrieNode{
        bool endOfWord;
        TrieNode* child[26];
        vector<int>indx; // storing the index of words which have
        // the same sorted string
        TrieNode(){
            endOfWord = 0;
            for(int i = 0;i<26;i++)
            child[i] = NULL;
            indx.clear();
        }
    };
    TrieNode *root;
    void insert(string &w,int index){
        TrieNode *p = root;
        for(auto ch:w){
            if(!p->child[ch-'a'])
            p->child[ch-'a'] = new TrieNode();
            p = p->child[ch-'a'];
        }
        p->endOfWord = 1;
        p->indx.push_back(index);
    }
    
    void helper(vector<string>& words,vector<vector<string>>&a,
                TrieNode *p){
        if(!p) return;
        if(p->endOfWord){
            vector<string>temp;
            for(auto i:p->indx)
            temp.push_back(words[i]);
            a.push_back(temp);
        }
        for(int i = 0;i<26;i++)
        if(p->child[i])
        helper(words,a,p->child[i]);
    }
    
  public:
    vector<vector<string> > Anagrams(vector<string>& words) {
        root = new TrieNode();
        for(int i = 0;i<words.size();i++){
            string g = words[i];sort(g.begin(),g.end());
            insert(g,i);
        }
        vector<vector<string>>ans;
        helper(words,ans,root);
        return ans;
    }
};
