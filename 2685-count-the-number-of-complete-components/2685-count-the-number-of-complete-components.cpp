class Solution {
public:
    void dfs(int curr,vector<vector<int>>&adj,vector<bool>&visited,int& vertexCount,int &edgeCount){
        visited[curr]=true;
        vertexCount++;
        edgeCount+=adj[curr].size();

        for(int ngbr:adj[curr]){
            if(!visited[ngbr]) dfs(ngbr,adj,visited,vertexCount,edgeCount);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(const auto&edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool>visited(n,false);
        int count=0;

        for(int i=0;i<n;i++){

            if(!visited[i]){
                int vertexCount=0;
                int edgeCount=0;

                dfs(i,adj,visited,vertexCount,edgeCount);

                if(edgeCount==vertexCount*(vertexCount-1)){
                    count++;
                }
            }
        }

        return count;
    }
};