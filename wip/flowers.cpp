#include <bits/stdc++.h>

const int mc = 10e5*2 + 10;
int f[mc],h[mc], dp[mc], N;

int main(){
    std::cin>>N;
    for(int i= 1; i <=N; i++){
        std::cin>>f[i];
        dp[i] =0;
    }for(int i = 1; i <=N;i++){std::cin>>h[i];}