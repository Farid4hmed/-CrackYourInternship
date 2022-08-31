class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) { 
            TreeNode* current = queue.front(); queue.pop();
            if(current->left) {
                parent[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent[current->right] = current;
                queue.push(current->right);
            }
        }
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) {
            int size = queue.size();
            if(curr_level++ == K) break;
            for(int i=0; i<size; i++) {
                TreeNode* current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent[current] && !visited[parent[current]]) {
                    queue.push(parent[current]);
                    visited[parent[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};
