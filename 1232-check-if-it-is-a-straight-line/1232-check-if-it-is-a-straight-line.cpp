class Solution {
private:
    int checkXEquals(vector<vector<int>>& coordinates, int n) {
        int cnt=1;
        for(int i=1;i<n;i++) {
            if(coordinates[i][0]==coordinates[i-1][0]) 
                cnt++;
        }
        return cnt;
    }
    
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        int check = checkXEquals(coordinates,n);
        if(check==n) 
            return true;
        else if(check>1) 
            return false;
        float m = (coordinates[1][1]-coordinates[0][1])/(float)(coordinates[1][0]-coordinates[0][0]);
        for(int i=1,j=(i+1);i<(n-1),j<n;i++,j++) {
            int x1 = coordinates[i][0];
            int y1 = coordinates[i][1];
            int x2 = coordinates[j][0];
            int y2 = coordinates[j][1];
            float slope = (y2-y1)/(float)(x2-x1);
            if(slope!=m) 
                return false;
        }
        return true;
    }
};