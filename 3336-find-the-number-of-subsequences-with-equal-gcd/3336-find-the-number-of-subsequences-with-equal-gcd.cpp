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
    int t[201][201][201];
    int solve(vector<int>&nums,int i,int g1,int g2){

        if(i==nums.size()){
            bool isBothEmpty=(g1!=0 && g2!=0);
            bool gcdMatch=(g1==g2);

            return (isBothEmpty && gcdMatch)?1:0; 
        }

        if(t[i][g1][g2]!=-1) return t[i][g1][g2];
        long long  skip=solve(nums,i+1,g1,g2);
        long long  take1=solve(nums,i+1,gcd(g1,nums[i]),g2);
        long long take2=solve(nums,i+1,g1,gcd(g2,nums[i]));

        return t[i][g1][g2]=( skip+take1+take2)%MOD;
    }
    int subsequencePairCount(vector<int>& nums) {

        memset(t,-1,sizeof(t));
        return solve(nums,0,0,0);
    }
};