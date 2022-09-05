class WordDictionary {
    struct TrieNode{
        TrieNode *child[26];
        bool isEnd;
        TrieNode(){
            isEnd = false;
            for(int i=0; i<26; i++){
                child[i] = NULL;
            }
        }
    };
public:
    WordDictionary() {
        
    }
    TrieNode* root = new TrieNode();
    void addWord(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.size(); i++){
            int index = word[i] - 'a';
            if(curr->child[index] == NULL)curr->child[index] = new TrieNode();
            curr = curr->child[index];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return helper(word, root);
    }
    bool helper(string word, TrieNode* node){
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(c != '.'){
                if(!node->child[c - 'a']) return false;
                node = node->child[c - 'a'];
            }
            else{
                bool found = false;
                int j = 0;
                for(; j < 26; j++){
                    if(node->child[j]) found |= helper(word.substr(i + 1), node->child[j]);
                    if(found) return true;
                }
                if(j == 26) return false;
            }
        }
        return node->isEnd;
    }
};
