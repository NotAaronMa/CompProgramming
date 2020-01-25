#include <bits/stdc++.h>
typedef long long ll;

int N,V;

int coins[2020], ans[100000];
ll dp[10002];
void tc(int j){
    j++;
    dp[0] = 0;
    for(int i = 0; i <= 10001; i++){
         if(i + coins[j] <= 10001 && dp[i] !=  __INT_MAX__){
                dp[i + coins[j]] = std::min(dp[i] + 1, dp[i + coins[j]]);
        }
    }
}

int main(){
    std::cin>>N>>V;
    
    for(int i= 1; i <= N; i++){
        std::cin>>coins[i];
    }
    for(int i = 0; i < 10001; i++){
        dp[i] = __INT_MAX__;
    }
    std::pair<int,int>q [V];
    for(int j = 0; j < V; j++){
        int C,L;
        std::cin>>C>>L;
        q[j] = std::make_pair(C,L);
    }

    
    for(int i = 0; i <= 2002; i++){
        for(int j = 0; j < V; j++){
            if(q[j].second == i){
                ans[j] = dp[q[j].first];
            }
        }
        tc(i);
    }
    for(int i = 0; i < V;i++){
        std::cout<<(ans[i] == __INT_MAX__? -1: ans[i])<<"\n";
    }
    

}