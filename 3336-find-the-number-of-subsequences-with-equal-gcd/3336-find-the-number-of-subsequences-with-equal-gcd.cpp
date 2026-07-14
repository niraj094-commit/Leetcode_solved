class Solution {
public:
    const int MOD=1e9+7;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    // int t[201][201][201];
    // int solve(vector<int>&nums,int i,int g1,int g2){

    //     if(i==nums.size()){
    //         bool isBothEmpty=(g1!=0 && g2!=0);
    //         bool gcdMatch=(g1==g2);

    //         return (isBothEmpty && gcdMatch)?1:0; 
    //     }

    //     if(t[i][g1][g2]!=-1) return t[i][g1][g2];
    //     long long  skip=solve(nums,i+1,g1,g2);
    //     long long  take1=solve(nums,i+1,gcd(g1,nums[i]),g2);
    //     long long take2=solve(nums,i+1,g1,gcd(g2,nums[i]));

    //     return t[i][g1][g2]=( skip+take1+take2)%MOD;
    // }
    int subsequencePairCount(vector<int>& nums) {
        
        int n=nums.size();
        int maxEl=-1;
        for(int x:nums) maxEl=max(maxEl,x);

        int dp[n+1][maxEl+1][maxEl+1];

        for(int g1=0;g1<=maxEl;g1++){
            for(int g2=0;g2<=maxEl;g2++){
                bool isBothEmpty=(g1!=0 && g2!=0);
                bool gcdMatch=(g1==g2);

                dp[n][g1][g2]=(isBothEmpty && gcdMatch)?1:0;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int g1=maxEl;g1>=0;g1--){
                for(int g2=maxEl;g2>=0;g2--){
                    long long skip=dp[i+1][g1][g2];
                    long long take1=dp[i+1][gcd(g1,nums[i])][g2];
                    long long take2=dp[i+1][g1][gcd(g2,nums[i])];

                    dp[i][g1][g2]=(skip+take1+take2)%MOD;
                }
            }
        }

        return dp[0][0][0];


    }
};