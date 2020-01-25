#include <bits/stdc++.h>


int dp[1010][1010];
//dp i j is max achievable rivarly score considering games 0-i w/hawks and 0-j w/geese
int main(){
    int N;
    std::cin>>N;
    std::pair<int,int> g[1010],h[1010];
    bool wl[1010];
    for(int i = 1; i <= N; i++){
        char c;
        std::cin>>c;
        wl[i] = c == 'W';
    }
    for(int i= 1; i <= N; i++){
        int n; std::cin>>n;
        g[i] = std::make_pair(wl[i],n);
    }
    for(int i = 1; i <= N; i++){
        char c;
        std::cin>>c;
        wl[i] = c == 'W';
    }
    for(int i= 1; i <= N; i++){
        int n; std::cin>>n;
        h[i] = std::make_pair(wl[i],n);
    }
    for(int* i : dp){
        memset(i,0,sizeof(i));
    }
    for(int i=1; i <= N; i++){
        for(int j = 1; j<= N; j++){
            dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            bool w1,w2; int p1,p2;
            w1 = g[i].first; w2 = h[j].first; p1 = g[i].second, p2 = h[j].second;
            if((w1 && !w2 && p1 > p2) || (w2 && !w1 && p2 > p1)){
                int alt = p1 + p2 + dp[i-1][j-1];
                dp[i][j] = std::max(dp[i][j],alt);
            }
        }
    }
    /*
    std::cout<<"\n";
    for(int i = 0;i <=N; i++){
        for(int j = 0;j <=N; j++){
            std::cout<<dp[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    */
    std::cout<<dp[N][N];

    

}

