class Solution {
public:
    bool isThree(int n) {
        if(n<4) return false;


        int  thirdOne=sqrt(n);

        if(thirdOne*thirdOne!=n) return false;

        for(int i=2;i*i<=thirdOne;i++){
            if(thirdOne%i==0) return false;
        }

        return true;
        
    }
};