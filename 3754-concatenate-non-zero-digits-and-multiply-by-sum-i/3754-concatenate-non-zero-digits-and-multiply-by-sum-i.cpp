class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        long long x=0;
        long long sum=0;
        for(char c:s){
            if(c!='0'){
                int dig=c-'0';
                x=x*10+dig;
                sum+=dig;
            }
        }

        return x*sum;
        
    }
};