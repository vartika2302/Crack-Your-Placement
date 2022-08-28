class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        vector<double>prob(n,0);
        // {probability, node}
        priority_queue<pair<double,int>>pq;
        prob[start]=1;
        pq.push({1,start});
        
        while(!pq.empty()){
            int node = pq.top().second;
            double p = pq.top().first;
            pq.pop();
            for(auto it: adj[node]) {
                if(prob[it.first] < p*(it.second)){
                    prob[it.first] = p*(it.second);
                    pq.push({prob[it.first],it.first});
                }
            }
        }
        
        return prob[end];
        
    }
};