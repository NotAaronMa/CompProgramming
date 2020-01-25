#include <bits/stdc++.h>

typedef long long ll;
int main(){
    int C,D,K;
    std::cin>>C>>D>>K;
    double w[D+1];
    int v[D+1],num[D+1];
    double dp[C+1];
    for(int i = 0; i < D; i++){
        std::cin>>v[i]>>w[i];
    }
    for(int i = 0; i < K; i++){
        int n;
        std::cin>>n;
        num[n]++;
    }

    return 0;
}