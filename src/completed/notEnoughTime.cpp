#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N,T;
std::tuple<ll,ll,ll> val[2020], wt[2020];
int dp[2][10001];


int main(){
    cin>>N>>T;
    for(int i = 1; i <= N; i++){
        int a,b,c,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        wt[i] = make_tuple(a,c,e);
        val[i] = make_tuple(b,d,f);
    }
    for(int*k: dp){
        for(int i = 0; i < T+1; i++){
            k[i] = 0;
        }
    }

    for(int n = 1; n <= N; n++){
        for(int t = 1; t <= T; t++){
            int notake = 0,badtake = 0,midtake =0,gudtake =0;
            //no take
            notake = max(dp[1][t-1], dp[0][t]);
            //bad take
            if(get<0>(wt[n]) <= t) badtake = dp[0][t - get<0>(wt[n])] + get<0>(val[n]);
            if(get<1>(wt[n]) <= t) midtake = dp[0][t - get<1>(wt[n])] + get<1>(val[n]);
            if(get<2>(wt[n]) <= t) gudtake = dp[0][t - get<2>(wt[n])] + get<2>(val[n]);
            int take = max(max(gudtake,midtake),badtake);
        
            dp[1][t] = max(take,notake);

        }
        swap(dp[0],dp[1]);
        
    }
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <=T;j++){
            //std::cout<<dp[N][T]<<" ";
        }
        //std::cout<<"\n";
    }
    std::cout<<dp[0][T];
    return 0;
}