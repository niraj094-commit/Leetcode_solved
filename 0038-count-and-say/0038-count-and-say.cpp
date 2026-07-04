class Solution {
public:
    vector<pair<char,int>> string_to_pairs(const string &s){
        vector<pair<char,int>> pairs;
        int n=s.length();
        int i=0;

        while(i<n){
            char curr=s[i];
            int cnt=0;
            while(i<n && s[i]==curr){
                cnt++;
                i++;
            }
            pairs.push_back({curr,cnt});
        }

        return pairs;
    }

    string pairs_to_string(const vector<pair<char,int>>&pairs){
        string res="";

        for(const auto& p:pairs){
            char dig=p.first;
            int fr=p.second;

            res+=to_string(fr)+dig;
        }

        return res;
    }
    string countAndSay(int n) {

        string ans="1";

        for(int i=1;i<n;i++){
            auto pairs=string_to_pairs(ans);
            ans=pairs_to_string(pairs);
        }

        return ans;
        
    }
};