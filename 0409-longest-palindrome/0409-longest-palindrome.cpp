class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(char c:s) mp[c]++;

        int cnt=0;
        bool isOdd=false;
        for(auto &it:mp){
            int fr=it.second;
            cnt+=(fr/2)*2;

            if(fr%2!=0) isOdd=true;

        }

        if(isOdd) cnt+=1;

        return cnt;
    }
};