class Solution {
public:
    int helper(string s,int l,int r){
        while(l>=0 && r<s.length() && s[l]==s[r]){
            l--,r++;
        }

        return r-l-1;
        
   }
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<1) return "";

        int st=0,maxLen=1;

        for(int i=0;i<n;i++){
            int l1=helper(s,i,i);
            int l2=helper(s,i,i+1);

            int len=max(l1,l2);

            if(len>maxLen){
                maxLen=len;
                st=i-(len-1)/2;

            }
        }

        return s.substr(st,maxLen);
        
    }
};