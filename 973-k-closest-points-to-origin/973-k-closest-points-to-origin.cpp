class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // O(nlogq)
        priority_queue<pair<int,vector<int>>>pq;
        for(auto point=0;point<points.size();point++){
            int d = (points[point][0]*points[point][0])+(points[point][1]*points[point][1]);
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