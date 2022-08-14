void setZeroes(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int columnSize = matrix[0].size();
        int column[columnSize];
        int row[rowSize];
        for(int i=0; i<columnSize; i++)column[i] = 1;
        for(int i=0; i<rowSize; i++)row[i] = 1;
        for(int i=0; i<rowSize; i++){
            for(int j=0; j<columnSize; j++){
                if(matrix[i][j] == 0){
                    column[j] = 0;
                    row[i] = 0;
                }
            }
        }
        
        for(int j=0; j<columnSize; j++){
            if(column[j] == 0){
                for(int i=0; i<rowSize; i++)matrix[i][j] = 0;
            }
        }
        
        for(int i=0; i<rowSize; i++){
            if(row[i] == 0){
                for(int j=0; j<columnSize; j++)matrix[i][j] = 0;
            }
        }
    }
