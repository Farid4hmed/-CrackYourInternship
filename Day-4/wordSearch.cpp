bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int l = word.size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(word[l-1] == board[i][j]){
                    if(find(board, word, l-1, i, j))return true;
                }
            }
        }
        return false;
    }
    
    bool find(vector<vector<char>>& board, string word, int l, int i, int j){
        int m = board.size();
        int n = board[0].size();
        char c = board[i][j];
        board[i][j] = '*';
        if(l==0)return true;
        else{
         bool up=false, down=false, left=false, right=false;
            if(i!=0 && board[i-1][j] == word[l-1])up = find(board, word, l-1, i-1, j);
            if(i!=m-1 && board[i+1][j] == word[l-1])down = find(board, word, l-1, i+1, j);
            if(j!=0 && board[i][j-1] == word[l-1])left = find(board, word, l-1, i, j-1);
            if(j!=n-1 && board[i][j+1] == word[l-1])right = find(board, word, l-1, i, j+1);
        if(up)return true;
        if(down)return true;
        if(left)return true;
        if(right)return true;
        }
        board[i][j] = c;
        return false;
    }
