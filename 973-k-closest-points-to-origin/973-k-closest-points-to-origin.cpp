class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // O(nlogq)
        priority_queue<pair<int,vector<int>>>pq;
        for(auto point=0;point<points.size();point++){
            int f = points[point][0];
            int l = points[point][1];
            int d = (f*f)+(l*l);
            pq.push({d,points[point]});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};