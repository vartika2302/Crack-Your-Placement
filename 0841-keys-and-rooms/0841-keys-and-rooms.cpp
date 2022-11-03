class Solution {
private:
    void dfs(int src, vector<vector<int>>& rooms, vector<int>& vis) {
        vis[src]=1;
        for(auto nbr: rooms[src]) {
            if(!vis[nbr]) {
                dfs(nbr,rooms,vis);
            }
        }
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n,0);
        dfs(0,rooms,vis);
        for(int i=0;i<n;i++) {
            if(vis[i]==0)
                return false;
        }
        return true;
    }
};