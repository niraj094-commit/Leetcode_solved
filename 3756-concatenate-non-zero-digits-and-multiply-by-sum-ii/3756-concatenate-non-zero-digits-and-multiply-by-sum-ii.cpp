class Solution {
public:

    typedef long long ll;
    const int MOD=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.length();

        vector<int>nonZeroCount(n,0);
        vector<ll> number_up_to(n,0);
        vector<ll>digit_sum_up_to(n,0);
        vector<ll> pow10(n+1,0);

        pow10[0]=1;
        for(int i=1;i<=n;i++){
            pow10[i]=(pow10[i-1]*10)%MOD;
        }

        nonZeroCount[0]=(s[0]!='0') ?1:0;

        for(int i=1;i<n;i++){
            int dig=s[i]-'0';
            nonZeroCount[i]=nonZeroCount[i-1]+(dig!=0?1:0);
        }

        number_up_to[0]=s[0]-'0';
        for(int i=1;i<n;i++){
            int dig=s[i]-'0';
            if(dig!=0){
                number_up_to[i]=(number_up_to[i-1]*10+dig)%MOD;
            }else{
                number_up_to[i]=number_up_to[i-1];
            }
        }

        digit_sum_up_to[0]=s[0]-'0';
        for(int i=1;i<n;i++){
            int dig=s[i]-'0';
            digit_sum_up_to[i]=digit_sum_up_to[i-1]+dig;
        }

        int q=queries.size();
        vector<int>res(q);

        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];

            ll sum=digit_sum_up_to[r]-((l==0)?0:digit_sum_up_to[l-1]);

            int check=(l==0)?0:number_up_to[l-1];
            int k=nonZeroCount[r]-((l==0)?0:nonZeroCount[l-1]);

            ll x=(number_up_to[r]-(check*pow10[k]%MOD)+MOD)%MOD;

            res[i]=(int)((x*sum)%MOD);
        }

        return res;
    }
};