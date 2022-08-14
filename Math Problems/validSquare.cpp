class Solution {
    int get_length(vector<int>& a, vector<int>& b){
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> sides = {
            get_length(p1, p2),
            get_length(p1, p3),
            get_length(p1, p4),
            get_length(p2, p3),
            get_length(p2, p4),
            get_length(p3, p4),
        };
        
        unordered_map<int, int> m;
        for(auto& s: sides){
            m[s]++;
        }
        
        if(!m.count(0) && m.size() == 2)return true;
        return false;
    }
};
