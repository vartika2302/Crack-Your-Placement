class Solution {
private:
    void bfs(int src, vector<int> adj[], vector<int>& vis) {
        queue<int>q;
        q.push(src);
        vis[src]=1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto nbr: adj[node]) {
                if(!vis[nbr]) {
                    q.push(nbr);
                    vis[nbr]=1;
                }
            }
        }
    }
    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<int>con_vis(n,0);
        int nodes=0;
        int connections_count=connections.size();
        for(int i=0;i<connections_count;i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            if(!con_vis[connections[i][0]]){
                nodes++;
                con_vis[connections[i][0]]=1;
            }
            if(!con_vis[connections[i][1]]){
                nodes++;
                con_vis[connections[i][1]]=1;
            }
        }
        
        vector<int>vis(n,0);
        int components=0;
        
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                components++;
                bfs(i,adj,vis);
            }
        }
        //cout<<components<<endl;
        
        // required wires - (components-1);
        int enough_wires = nodes-1;
        int extra_wires = connections_count-enough_wires;
        int required_wires = components-1;
        if(extra_wires>=required_wires) {
            return required_wires;
        }
        return -1;
        
    }
};