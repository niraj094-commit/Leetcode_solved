class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxEl=0;
        int i=0;
        int n=nums.size();
        vector<int>prefixGcd(n);
        for(int i=0;i<n;i++){
            maxEl=max(nums[i],maxEl);
            prefixGcd[i]=gcd(maxEl,nums[i]);
        }

        sort(prefixGcd.begin(),prefixGcd.end());
        long long  sum=0;

        for(int i=0,j=nums.size()-1;i<nums.size()/2;i++,j--){
            sum+=gcd(prefixGcd[i],prefixGcd[j]);
        }

        return sum;
        
    }
};