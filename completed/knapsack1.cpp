#include <bits/stdc++.h>
typedef long long ll;


int main(){
    ll N,W,w[200],v[200],dp[2][100010]; std::cin>>N>>W;
    for(int i = 1; i<= N; i++){
        std::cin>>w[i]>>v[i];
    }
    
    for(int i = 0; i < W+1; i++){
        dp[0][i] = 0;
        dp[1][i] = 0;
    }

    for(int i = 1; i <= N; i++){
        for(int wt = 1; wt <= W; wt++){


            ll take=0,notake =0;

            notake =std::max(dp[1][wt-1], dp[0][wt]);
            if(w[i] <= wt){
                take = dp[0][wt-w[i]] + v[i];
            }

            dp[1][wt] = std::max(take,notake);
        }
        std::swap(dp[1],dp[0]);
    }
 
    std::cout<<dp[0][W];
    return 0;
}
