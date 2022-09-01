class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* lca(Node* root,int a,int b){
     if(!root) return NULL;
     if(root->data==a||root->data==b) return root;
     Node* l= lca( root->left,a, b);
     Node* r= lca( root->right, a,b);
     if(!l) return r;
     if(!r) return l;
     return root;
 }
     void Dist(Node *root,int a,int &d,int dist){
        if(root==NULL)return;
        if(root->data==a){
            d=dist;
            return ;
        }
        Dist(root->left,a,d,dist+1);
        Dist(root->right,a,d,dist+1);
        
    }
   int findDist(Node* root, int a, int b) {
       root=lca(root,a,b);
       int d1,d2;
        Dist(root,a,d1,0);
        Dist(root,b,d2,0);
      return d1+d2;
   }
};
