class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>comp(n,0);
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                comp[i]=comp[i-1];
            }else{
                comp[i]=comp[i-1]+1;
            }
        }

        int q=queries.size();
        vector<bool>res(q);

        for(int i=0;i<q;i++){
            int u=queries[i][0];
            int v=queries[i][1];

            res[i]=(comp[u]==comp[v]);
        }

        return res;
    }
};