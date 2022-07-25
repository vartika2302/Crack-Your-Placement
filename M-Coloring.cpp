class Solution{
public:
    
    
    bool isPossible(int node,int n,int col,bool graph[101][101],int color[]){
        // for every node
        for(int k=0;k<n;k++){
            if(k!=node && graph[k][node]==1 && color[k]==col){
                return false;
            }
        }
        return true;
    }

    bool solve(int node,int m,int n,bool graph[101][101],int color[]){
        if(node==n) return true;
        for(int col=1;col<=m;col++){
            if(isPossible(node,n,col,graph,color)){
                color[node] = col;
                if(solve(node+1,m,n,graph,color)) return true;
                color[node] = 0;
            }
        }
        return false;
    }

    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n] = {0};
        if(solve(0,m,n,graph,color)) return true;
        return false;
        
    }
};
