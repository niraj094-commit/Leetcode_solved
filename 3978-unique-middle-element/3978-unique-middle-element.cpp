class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int ,int>mp;
        int mid=nums[n/2];
        for(int x:nums) mp[x]++;

        for(auto&p:mp){
            if(p.first==mid){
                if(p.second>1) return false;
            }
        }

        return true;
        
    }
};