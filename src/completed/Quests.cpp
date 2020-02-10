#include <bits/stdc++.h>
typedef long long ll;
int N,H;

ll dp[2][5010];
int main(){
    std::cin>>N>>H;
    int p=0,c=1;
    for(int i = 1; i <= N; i++){
        int g,h,g1,h1; std::cin>>g>>h>>g1>>h1;
        for(int i = 0; i < 5010; i++){
            dp[c][i] = 0;
        }
        //goto i
        for(int t = h; t <= H; t++){
            dp[c][t] = dp[p][t-h] + g;
        }
        //quest do bois
        for(int t = h + h1; t <= H; t++){
            dp[c][t] = std::max(dp[c][t-h1] + g1,dp[c][t]);
        }        
        //check if current npc sucks 
        for(int t = 1; t <= H; t++){
            dp[c][t] = std::max(dp[c][t],dp[p][t]);
        }
        std::swap(p,c);
    }
    std::cout<<dp[p][H];
}
