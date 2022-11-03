class Solution {
private:
    // void dfs(int src, vector<vector<int>>& rooms, vector<int>& vis) {
    //     vis[src]=1;
    //     for(auto nbr: rooms[src]) {
    //         if(!vis[nbr]) {
    //             dfs(nbr,rooms,vis);
    //         }
    //     }
    // }
    
    void bfs(int src, vector<vector<int>>& rooms, vector<int>& vis) {
        queue<int>q;
        q.push(src);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            vis[node]=1;
            for(auto nbr: rooms[node]) {
                if(!vis[nbr]) {
                   q.push(nbr);
                }
            }
        }
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n,0);
        bfs(0,rooms,vis);
        for(int i=0;i<n;i++) {
            if(vis[i]==0)
                return false;
        }
        return true;
    }
};