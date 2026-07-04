class Solution {
public:

    void dfs(unordered_map<int,vector<pair<int,int>>> &adj,int u,vector<bool>& vis,int &res){
        vis[u]=true;

        for(auto& vec:adj[u]){
            int v=vec.first;
            int w=vec.second;


            res=min(res,w);

            if(!vis[v]){
                dfs(adj,v,vis,res);
            }
        }

    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto& vec:roads){
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<bool>vis(n,false);
        int res=INT_MAX;
        dfs(adj,1,vis,res);

        return res;
        
    }
};