class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(arr.empty()) return {};
        vector<pair<int,int>>set;
        for(int i=0;i<arr.size();i++){
            set.push_back({arr[i],i});

        }

        sort(set.begin(),set.end());
        int rank=1;
        vector<int>ans(n);
        ans[set[0].second]=rank;
        for(int i=1;i<set.size();i++){
            if(set[i].first!=set[i-1].first) rank++;

            ans[set[i].second]=rank;
        }

        return ans;
        
    }
};