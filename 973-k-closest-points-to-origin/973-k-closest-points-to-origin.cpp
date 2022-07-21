class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // O(nlogq)
        // priority_queue<pair<int,vector<int>>>pq;
        // for(auto point=0;point<points.size();point++){
        //     int f = points[point][0];
        //     int l = points[point][1];
        //     int d = (f*f)+(l*l);
        //     pq.push({d,points[point]});
        //     if(pq.size()>k) pq.pop();
        // }
        // vector<vector<int>>ans;
        // while(!pq.empty()){
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return ans;
        
         nth_element(begin(points), begin(points) + k, end(points), [](vector<int> &a, vector<int> &b) {
      return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
  });
  points.resize(k);
  return points;
        
    }
};