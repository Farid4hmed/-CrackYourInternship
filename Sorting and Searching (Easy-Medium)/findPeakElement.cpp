class Solution{
public: 
    int findPeakElement(vector<int> &array){
        int i=0; int j=array.size()-1;
        int m;

        int li = array.size()-1;
        if(li==0)   return 0;
        while(i<=j){
            m = i + (j-i)/2;

        if(m>0 && m<li){
            if(array[m-1] < array[m] && array[m] > array[m+1])return m;
            else if(array[m-1]>array[m+1]) j=m-1;
            else i=m+1;
            }

            else if(m==0){
                if(array[m]>array[m+1])   return m;
                else i=m+1;
            }

            else{
                if(array[m]>array[m-1])   return m;
                else j=m-1;
            }
        }

        return -1;
    }
};
