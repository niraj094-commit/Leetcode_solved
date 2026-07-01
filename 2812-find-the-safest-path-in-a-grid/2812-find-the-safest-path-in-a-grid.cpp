class Solution {
public:
    int n;
    vector<vector<int>> directions{{1,0},{-1,0},{0,-1},{0,1}};

    bool isValidPath(vector<vector<int>>&dist,int sf){

        if (dist[0][0] < sf || dist[n - 1][n - 1] < sf) return false;
        queue<pair<int ,int>>q;
        vector<vector<bool>>visited(n,vector<bool>(n,false));

        q.push({0,0});
        visited[0][0]=true;

        while(!q.empty()){
            int curr_i=q.front().first;
            int curr_j=q.front().second;

            q.pop();

            if(curr_i==n-1 && curr_j==n-1) return true;

            for(vector<int>&dir:directions){
                int new_i=curr_i+dir[0];
                int new_j=curr_j+dir[1];

                if(new_i>=0 && new_i<n && new_j>=0 && new_j<n  && visited[new_i][new_j]!=true){
                    if(dist[new_i][new_j]<sf){
                        continue;
                    }

                    q.push({new_i,new_j});
                    visited[new_i][new_j]=true;
                }
            }
        }

        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();

        vector<vector<int>>dist(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(n,vector<bool>(n,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }

        }

        int level=0;
        while(!q.empty()){
            int size=q.size();

            while(size--){
                int curr_i=q.front().first;
                int curr_j=q.front().second;

                q.pop();

                dist[curr_i][curr_j]=level;
                for(vector<int>&dir:directions){
                    int new_i=curr_i+dir[0];
                    int new_j=curr_j+dir[1];

                    if(new_i<0 ||new_i>=n || new_j<0 ||new_j>=n||visited[new_i][new_j]!=false){
                        continue;
                    }

                    q.push({new_i,new_j});
                    visited[new_i][new_j]=true;
                }
            }
            level++;
        }

        //Binary search on SF

        int l=0,r=800;
        int res=0;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(isValidPath(dist,mid)){
                res=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }

        return res;
    }
};