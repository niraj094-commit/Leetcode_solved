class Solution {
public:
    int gcdOfOddEvenSums(int n) {

        int s1=0,s2=0;
        for(int i=1;i<=2*n;i++){
            if(i%2!=0) s1+=i;
            else s2+=i;
        }

        return gcd(s1,s2); 
        
    }
};