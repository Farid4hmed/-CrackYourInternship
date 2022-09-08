class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        if(a.size()<2) return 0;
        sort(a.begin(),a.end());
		
        int e = a[0][1];
        int res = 0;
		
        for(int i=1;i<a.size();i++){
            if(e>a[i][0]){
                res++;
                e = min(e,a[i][1]);
            }
            else e = a[i][1];
        }
        return res;
    }
};
