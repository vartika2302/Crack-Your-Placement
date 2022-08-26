class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& stack) {
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,stack);
            }
        }
        stack.push(node);
    }
    
    bool detect_cycle(int node, vector<int> adj[], vector<int>& visi, vector<int>& dfs_vis){
        visi[node]=1;
        dfs_vis[node]=1;
        for(auto it: adj[node]){
            if(!visi[it]){
                if(detect_cycle(it,adj,visi,dfs_vis)) return true;
            }else if(dfs_vis[it]) return true;
        }
        dfs_vis[node]=0;
        return false;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>topo;
        
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++) {
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            adj[from].push_back(to);
        }
        
        
        vector<int>visi(numCourses,0);
        vector<int>dfs_vis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visi[i]){
                if(detect_cycle(i,adj,visi,dfs_vis)) return topo;
            }
        }
        
        
        stack<int>stack;
        vector<int>vis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                dfs(i,adj,vis,stack);
            }
        }
       
        
        while(!stack.empty()){
            topo.push_back(stack.top());
            stack.pop();
        }
        return topo;
    }
};