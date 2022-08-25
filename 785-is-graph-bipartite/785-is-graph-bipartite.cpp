class Solution {
private:
    bool checkBipartite(vector<vector<int>>& graph, int src, int color[]){
        color[src]=0;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : graph[node]){
                if(color[it]==-1){
                    color[it] = 1-color[node];
                    q.push(it);
                }else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int color[V];
        memset(color, -1, sizeof color);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(checkBipartite(graph,i,color)==false) return false;
            }
        }
        return true;
    }
};