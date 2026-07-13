class Solution {
public:
    void dfs(long long currNum,int ld,int low ,int high,vector<int>&res){
        if(currNum>=low && currNum<=high) res.push_back(currNum);

        if(currNum>high || ld ==9) return ;

        dfs(currNum*10+(ld+1),ld+1,low ,high,res);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>res;

        for(int i=1;i<=8;i++) dfs(i,i,low,high,res);

        sort(res.begin(),res.end());
        return res;

    }
};