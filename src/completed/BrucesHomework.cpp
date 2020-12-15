#include <bits/stdc++.h>

using ld = long double;
const int mm = 105;

int t[mm];
ld s[mm], dp[mm][8641];




int main(){
    int N,M,T; std::cin>>N>>M>>T;
    for(int i = 1; i <= N; i++){
        std::cin>>t[i];
        s[i] = 0;
    }

    ld base = 0;
    for(int i = 1; i <= M; i++){
        int ki; std::cin>>ki;
        if(ki == 0){
            base++;
        }
        for(int i = 0; i < ki; i++){
            int q; std::cin>>q;
            s[q] += 1/(ld)ki;
        }
    }



    for(int i = 0; i < mm;i++){
        for(int j = 0; j < mm;j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i <= N; i++){
        for(int wt = 1; wt <= T; wt++){
            ld take = 0, notake = 0;
            notake = std::max(dp[i-1][wt],dp[i][wt-1]);
            if(t[i] <= wt){
               
                take = dp[i-1][wt-t[i]] + s[i];
            }
  
            dp[i][wt] = std::max(notake,take);
        }
    }
    std::cout<<std::fixed<<std::setprecision(2)<<dp[N][T] + base;
    
}