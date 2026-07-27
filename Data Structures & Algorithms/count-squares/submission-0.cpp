class CountSquares {
public:
vector<vector<int>>coordinates;
map<vector<int>,int>ptscount;
    CountSquares() {
    }
    
    void add(vector<int> point) {
        coordinates.push_back(point);
        ptscount[point]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        for(vector<int>coord :coordinates){
            if(abs(point[0] - coord[0]) == abs(point[1] - coord[1]) and coord[0]!=point[0] and coord[1] != point[1]){
               res+=ptscount[{coord[0],point[1]}] * ptscount[{point[0],coord[1]}];
            }
        }
        return res;
    }
};
