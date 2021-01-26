#include <bits/stdc++.h>
using ll = long long;
const int mm = 1e5+5, mod = 1000000000+7;
int a[401];
ll dp[401][mm], ps[mm];





void sm(int n){
    memset(ps,0,sizeof(ps));
    ps[0] = dp[n][0];
    for(int i = 1; i <mm; i++){
        ps[i] = ps[i-1] + dp[n][i]%mod;
        ps[i] %= mod;
    }
}

int main(){
    int n, k; std::cin>>n>>k;
    memset(dp,0,sizeof(dp));
    memset(ps,0,sizeof(ps));
    memset(a,0,sizeof(a));
    for(int i = 1; i <= n; i++){
        std::cin>>a[i];
    }



    for(int i = 0; i <= a[1]; i++){
        dp[1][i] = 1;
    }
    sm(1);

    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= k;j++){

            if(j <= a[i]){
                dp[i][j] = ps[j];
            }
            else{
                dp[i][j] = ps[j] - ps[j-a[i] -1];

                while(dp[i][j] < 0){
                    dp[i][j] += mod;
                }
            }
            dp[i][j] %= mod;
        }
        sm(i);


    }
    std::cout<<dp[n][k]%mod;

    return 0;
}