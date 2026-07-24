class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        unordered_set<int> st(nums.begin(),nums.end());

        vector<bool>dp(2048,false);
        dp[0]=true;

        for(int cnt=0;cnt<3;cnt++){
            vector<bool>ndp(2048,false);
            for(int x:st){
                for(int i=0;i<2048;i++){
                    if(dp[i]){
                        ndp[i^x]=true;
                    }
                }
            }
            dp=move(ndp);
        }

        int ans=0;
        for(bool isReached:dp){
            if(isReached) ans++;
        }

        return ans;
        
    }
};