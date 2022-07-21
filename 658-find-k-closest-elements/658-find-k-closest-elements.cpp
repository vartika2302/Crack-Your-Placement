class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k) pq.pop();
        }
        
        multiset<int>m;
        while(!pq.empty()) {
            m.insert(pq.top().second);
            pq.pop();
        };
        vector<int>ans(m.begin(),m.end());
        return ans;
    }
};