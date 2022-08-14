vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int mfirst = 0, mlast = matrix.size()-1;
        int nfirst = 0, nlast = matrix[0].size()-1;
        
        vector <int> v;
        
        while(1){
            //left to right
            for(int j=nfirst; j<=nlast; j++)v.push_back(matrix[mfirst][j]);
            mfirst++;
            if(mfirst>mlast)break; 
            
            //top to bottom
            for(int i=mfirst; i<=mlast; i++)v.push_back(matrix[i][nlast]);
            nlast--;
            if(nfirst>nlast)break;
            
            //right to left
            for(int j=nlast; j>=nfirst; j--)v.push_back(matrix[mlast][j]);
            mlast--;
            if(mfirst>mlast)break;
            
            //bottom to top
            for(int i=mlast; i>=mfirst; i--)v.push_back(matrix[i][nfirst]);
            nfirst++;
            if(nfirst>nlast)break;
            
            //repeat with updated values
        }
        return v;
    }
