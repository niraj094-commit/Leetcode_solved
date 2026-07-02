class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(),n=grid[0].size();

        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        deque<pair<int,int>>dq;

        vector<vector<int>>dir={{0,-1},{1,0},{0,1},{-1,0}};

        dist[0][0]=grid[0][0];
        dq.push_front({0,0});

        while(!dq.empty()){
            auto[x,y]=dq.front();dq.pop_front();

            for(auto&it:dir){
                int nx=x+it[0],ny=y+it[1];

                if(min(nx,ny)>=0 && nx<m && ny<n){
                    int cost=grid[nx][ny];
                    int newDist=cost+dist[x][y];
                    if(newDist<dist[nx][ny]){
                        dist[nx][ny]=newDist;
                        if(cost==0) dq.push_front({nx,ny});
                        else dq.push_back({nx,ny});
                    }
                }
            }
        }

        return dist[m-1][n-1]<health;
        
    }
};