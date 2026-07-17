class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());

        int n=s.length();
        int rightIdx=0;

        for(int st=0;st<n;st++){
            if(s[st]!=' '){
                if(rightIdx!=0) s[rightIdx++]=' ';

                int end=st;
                while(end<n&& s[end]!=' '){
                    s[rightIdx++]=s[end++];
                }

                reverse(s.begin()+rightIdx-(end-st),s.begin()+rightIdx);

                st=end;
            }
        }

        s.erase(s.begin()+rightIdx,s.end());
        return s;
        
        
        
    }
};