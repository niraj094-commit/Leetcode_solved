class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int cnt=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int curr_gcd=nums[i];

            for(int j=i;j<n;j++){
                curr_gcd=gcd(curr_gcd,nums[j]);

                if(curr_gcd==k) cnt++;
                else if(curr_gcd%k!=0) break;
            }

            
        }

        return cnt;
    }
};