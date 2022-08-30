bool findDeadEnd(Node* root, int min, int max){
    if(!root)return false;
    if(min == max)return true;
    bool left = findDeadEnd(root->left, min, root->data-1);
    bool right = findDeadEnd(root->right, root->data+1, max);
    if(left || right)return true;
    return false;
    
}
bool isDeadEnd(Node *root)
{
    return findDeadEnd(root, 1, INT_MAX);
}
