class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'A' || 
               c == 'e' || c == 'E' || 
               c == 'i' || c == 'I' || 
               c == 'o' || c == 'O' || 
               c == 'u' || c == 'U';
    }
    string reverseVowels(string s) {
        int l=0,r=s.length()-1;
        while(l<r){
            while(l<r && !isVowel(s[l])) l++;
            while(l<r && !isVowel(s[r])) r--;

            if(l<r){
                swap(s[l],s[r]);
                l++;r--;
            }
        }
        

        return s;

        
    }
};