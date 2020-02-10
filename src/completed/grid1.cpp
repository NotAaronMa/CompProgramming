#include <bits/stdc++.h>
typedef long long ll;
const ll mod = 1000000007;
ll dp[1010][1010];
bool map[1010][1010];
int H,W;


int main(){
    std::cin>>H>>W;
    for(bool* mi : map){
        memset(mi,1,sizeof(mi));
        mi[0] = 0;
        mi[W+1] = 0;
    }
    for(ll* k : dp){memset(k,0,sizeof(k));}

    memset(map[0], 0, sizeof(map[0]));
    memset(map[H+1], 0, sizeof(map[0]));
    dp[1][1] = 1;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            char c;
            std::cin>>c;
            map[i][j] = (c == '#'? false : true);
        }
    }
    //for(int i = 0; i < 10; i++){
    for(int f = 0; f <= H; f++){
        for(int s = 0; s <= W; s++){
            if(map[f + 1][s]){
                dp[f + 1][s] += dp[f][s];

            }
            if(map[f][s + 1]){
                dp[f][s + 1]+= dp[f][s];
            }
            dp[f][s] %= mod;
            dp[f][s+1] %=mod;
            dp[f+1][s] %=mod;
        }
    }
    std::cout<<(dp[H][W] % mod);
    
}