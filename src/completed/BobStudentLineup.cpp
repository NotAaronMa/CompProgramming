#include <bits/stdc++.h>
using str = std::string;
const int mm = 300005;
int dp[mm], facing[mm];

int main(){
    str s;
    int n; std::cin>>n>>s;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n;i++){
        facing[i+1] = (s[i] == 'R');
    }

    for(int i = 2; i <= n;i++){
        dp[1] += facing[i];
    }
    int dpm = dp[1];


    //std::cout<<dp[1]<<"\n";
    for(int i = 2; i <= n;i++){
        dp[i] = dp[i-1];
        if(facing[i] == 1){
            dp[i]--;
        }
        if(facing[i-1] == 0){
            dp[i] ++;
        }
        dpm = std::min(dp[i],dpm);

       // std::cout<<i<<": "<<dp[i]<<"\n";
    }
    std::cout<<dpm;
   

    return 0;
}