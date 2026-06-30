class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        unordered_map<char,int> mp;
        int num=0;

        int l=0,r=0;
        while(r<n){
            mp[s[r]]++;

            while(mp.size()>=3){
                num+=(n-r);
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            r++;
        }

        return num;

        
    }
};