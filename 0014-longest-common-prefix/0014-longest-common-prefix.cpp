struct Trie{
    Trie* children[26];
    bool endOfWord;
    int childCount;

    Trie(){
        endOfWord=false;
        childCount=0;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};

class Solution {
    Trie *root;

    void insert(const string & word){
        Trie* curr=root;
        for(char c:word){
            int Idx=c-'a';
            if(curr->children[Idx]==NULL){
                curr->children[Idx]=new Trie();
                curr->childCount++;
            }
            curr=curr->children[Idx];
        }
        curr->endOfWord=true;
    }   
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        root=new Trie();

        for(const string& word:strs){
            if(word.empty()) return "";
            insert(word);
        }

        string prefix="";
        Trie* curr=root;

        while(curr->childCount==1 && !curr->endOfWord){
            int nextIdx=-1;

            for(int i=0;i<26 ;i++){
                if(curr->children[i]!=NULL){
                    nextIdx=i;
                    break;
                }
            }

            if(nextIdx==-1) break;

            prefix+=(nextIdx+'a');
            curr=curr->children[nextIdx];
        }

        return prefix;
        
    }
};