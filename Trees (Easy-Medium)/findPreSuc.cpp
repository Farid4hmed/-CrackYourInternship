void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{   
    while(root and root->key!=key){
       if(key<root->key) {
           suc = root;
           root = root->left;
       }
       else{
           pre = root;
           root = root->right;
       }
   }
   
   if(root and root->key==key){
       if(root->left){
           Node* curr = root->left;
           while(curr){
               pre = curr;
               curr = curr->right;
           }
       }
       if(root->right) {
           Node* curr = root->right;
           while(curr){
               suc = curr;
               curr = curr->left;
           }
       }
   }
}
