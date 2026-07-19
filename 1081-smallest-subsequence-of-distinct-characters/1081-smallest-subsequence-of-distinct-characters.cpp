class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIdx(26,0);
        vector<bool> seen(26,false);
        string res="";

        for(int i=0;i<s.length();i++){
            lastIdx[s[i]-'a']=i;

        }

        for(int i=0;i<s.length();i++){
            int curr=s[i]-'a';

            if(seen[curr]) continue;

            while(!res.empty()&& s[i]<res.back() && i<lastIdx[res.back()-'a']){
                seen[res.back()-'a']=false;
                res.pop_back();
            }

            res.push_back(s[i]);
            seen[curr]=true;
        }

        return res;
        
    }
};