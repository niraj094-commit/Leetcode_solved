class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int cnt_1=0,n=s.length();
        for(char c:s){
            if(c=='1') cnt_1++;
        }

        vector<int>inactiveBlocks;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int st=i;
                while(i<n &&s[i]=='0') i++;

                inactiveBlocks.push_back(i-st);
            }else{
                i++;
            }
        }


        

        int max_pair_sum=0;
        for(int i=1;i<inactiveBlocks.size();i++){
            max_pair_sum=max(max_pair_sum,inactiveBlocks[i]+inactiveBlocks[i-1]);
        }

        return max_pair_sum+cnt_1;
        
    }
};