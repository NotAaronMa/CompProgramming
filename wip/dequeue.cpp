#include <bits/stdc++.h>
typedef long long ll;
//dp[i][j] is the max value one can obtain if given segment i-j inclusive
int a[3030],N;
ll dp[3030][3030];
bool take[3030];
//s to e inclusive interval
int iv(int s,int e,int pre){
    if(s > e){
        return 0;
    }
    if(s == e){
        //if 1 elem return the elem
        return a[s];

    //if already solved
    }else if(dp[s][e] != -__INT_MAX__){
        return dp[s][e];
    }else{
        //take front vs take back
        dp[s][e] =  std::max(iv(s+1,e,pre+a[s]),iv(s,e-1,pre+a[s]));
        std::cout<<s<<" "<<e<<" "<<dp[s][e]<<"\n";
        return dp[s][e];
    }
    
}

int main(){
    std::cin>>N;
    for(int i = 1; i <= N; i++){
        std::cin>>a[N];
    }
    for(ll* i : dp){ for(int j = 0; j < 3030; j++){i[j] = -__INT_MAX__;}}
    std::cout<<iv(1,N,0);
}