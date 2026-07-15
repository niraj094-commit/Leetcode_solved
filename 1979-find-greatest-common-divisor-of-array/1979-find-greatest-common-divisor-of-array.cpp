class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx=INT_MIN,mn=INT_MAX;
        for(int x:nums){
            if(x<=mn) mn=x;
            if(x>=mx) mx=x;
        }

        int ans=0;
        for(int i=1;i<=mn;i++){
            if((mn%i==0)&& (mx%i==0)) ans=max(ans,i);
            
        }

        return ans;
        
    }
};