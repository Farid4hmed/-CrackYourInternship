class Solution{
    struct TrieNode{
        bool isEnd;
        TrieNode* child[26];
        TrieNode(){
            isEnd = false;
            for(int i=0; i<26; i++)child[i] = NULL;
        }
    };
    public:
    // A : given string to search
    // B : vector of available strings
    TrieNode* root = new TrieNode();
    void insert(string &key){
        TrieNode* curr = root;
        for(int i=0; i<key.size(); i++){
            int index = key[i] - 'a';
            if(curr->child[index] == NULL)curr->child[index] = new TrieNode();
            curr = curr->child[index];
        }
        curr->isEnd = true;
    }
    
    bool search(string &key){
        TrieNode* curr = root;
        for(int i=0; i<key.size(); i++){
            int index = key[i] - 'a';
            if(curr->child[index] == NULL)return false;
            curr = curr->child[index];
        }
        return curr->isEnd;
    }
    bool func(string &s,int j,TrieNode *head){
       if(j==s.size()) return true;
       string t;
       for(int i=j;i<s.size();i++){
           t.push_back(s[i]);
           if(search(t) && func(s,i+1,head)) return 1;
       }
       return 0;
   }
    int wordBreak(string A, vector<string> &B) {
        for(auto str: B)insert(str);
        TrieNode* t = new TrieNode();
        return func(A, 0, t);
   }
};
