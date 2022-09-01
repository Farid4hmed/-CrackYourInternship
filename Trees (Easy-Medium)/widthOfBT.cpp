class Solution {
public:
    unsigned long long int max_width = 0;
    unordered_map<unsigned long long int, unsigned long long int> m;
    void get_width(TreeNode* root, unsigned long long int depth, unsigned long long int pos){
        if(root == NULL)return;
        if(m.find(depth) == m.end())m[depth] = pos;
        max_width = max(max_width, pos - m[depth] + 1);
        get_width(root->left, depth+1, pos*2);
        get_width(root->right, depth+1, pos*2+1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        get_width(root, 0, 0);
        return max_width;
    }
};
