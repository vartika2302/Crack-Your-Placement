class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int dis = INT_MAX;
        for(int i=0;i<points.size();i++) {
            int xcor = points[i][0];
            int ycor = points[i][1];
            if(xcor==x || ycor==y) {
                dis = min(dis,abs(xcor-x)+abs(ycor-y));
            }
        }
        if(dis==INT_MAX) return -1;
        
        for(int i=0;i<points.size();i++) {
            int xcor = points[i][0];
            int ycor = points[i][1];
            if((xcor==x || ycor==y) && abs(xcor-x)+abs(ycor-y)==dis) {
                return i;
            }
        }
        return 0;
    }
};