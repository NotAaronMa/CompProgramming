#include <bits/stdc++.h>

const int mx = 3005;

//dp[i][j] is probability i coins flipped with j heads;

long double dp[mx][mx], coins[mx];


int main(){

    std::cout.precision(std::numeric_limits<long double>::max_digits10);
    for(long double* i : dp){
        memset(i,0,sizeof(i));
    }
    int n; std::cin>>n;
    for(int i = 1; i <= n; i++){
        std::cin>>coins[i];
    }

    dp[1][1] = coins[1];
    dp[1][0] = 1-coins[1];
    for(int i = 2; i <= n; i++){
        dp[i][0] = dp[i-1][0]*(1-coins[i]);
        //dp[i][i] = dp[i-1][i-1]*coins[i];
        for(int j = 1; j<=n; j++){
            dp[i][j] += coins[i]*dp[i-1][j-1];
            dp[i][j] += (1-coins[i]) * dp[i-1][j];
        }
    }
    long double p = 0;
    for(int i = n/2+1; i <= n; i++){
        
        p+=dp[n][i];
    }
    std::cout<<p<<"\n";


    return 0;
}