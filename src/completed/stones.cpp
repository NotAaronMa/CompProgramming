#include <bits/stdc++.h>

int N,K;
int main(){
    std::cin>>N>>K;
    int a[110];
    signed char dp[(int)10e5 +7];
    for(int i = 1; i <= N; i++){
        std::cin>>a[i];
    }
    for(int i = 0; i <= K+10; i++){
        dp[i] = -1;
    }    

    //0 loose 1 win
    //no moves possible
    for(int i = 0; i < a[1]; i++){
        dp[i] = 0;
    }
    for(int i = 0; i <= K+10; i++){
        for(int j = 1; j <= N; j++){
            //only update if dp[i + a[j]] is win or undetermined 
            //since can still force loss
            if(i + a[j] <= K+10){
                if(dp[i + a[j]] != 1 && dp[i]!= -1){
                    dp[i + a[j]] = !dp[i];
                }
            }
            //std::cout<<i + a[j]<<" "<<dp[i+a[j]];
        }
        //std::cout<<dp[i]<<" ";
        
    }
    std::cout<<(dp[K] ? "First" : "Second");

    return 0;
}