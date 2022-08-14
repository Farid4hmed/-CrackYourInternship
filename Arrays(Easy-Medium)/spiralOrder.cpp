vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int mfirst = 0, mlast = matrix.size()-1;
        int nfirst = 0, nlast = matrix[0].size()-1;
        
        vector <int> v;
        
        while(1){
            for(int j=nfirst; j<=nlast; j++)v.push_back(matrix[mfirst][j]);
            mfirst++;
            if(mfirst>mlast)break;
            
            for(int i=mfirst; i<=mlast; i++)v.push_back(matrix[i][nlast]);
            nlast--;
            if(nfirst>nlast)break;
            
            for(int j=nlast; j>=nfirst; j--)v.push_back(matrix[mlast][j]);
            mlast--;
            if(mfirst>mlast)break;
            
            for(int i=mlast; i>=mfirst; i--)v.push_back(matrix[i][nfirst]);
            nfirst++;
            if(nfirst>nlast)break;
        }
        return v;
    }
