void insert(struct TrieNode *root, string key)
{
    // code here
    for(int i=0;i<key.size();i++){
       int idx=key[i]-'a';
       if(root->children[idx]==NULL)
           root->children[idx]=new TrieNode();
       root=root->children[idx];
   }
   root->isLeaf=true;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    for(int i=0;i<key.size();i++){
       int idx=key[i]-'a';
       if(root->children[idx]==NULL)
           return false;
       root=root->children[idx];
   }
   return root->isLeaf;
}
