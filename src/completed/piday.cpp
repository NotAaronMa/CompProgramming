#include <bits/stdc++.h>


int dp[300][300];
int solve(int ppl,int pi){
    //if 0 people or 1 pie return 0
    if(ppl == 1 || pi <= 1){
        return 1;       
    }
    if(dp[ppl][pi] == -1){
        dp[ppl][pi] = 0;
        dp[ppl][pi] += solve(ppl-1, pi);
        if(pi >= ppl) dp[ppl][pi]+= solve(ppl,pi-ppl);
    }
    return dp[ppl][pi];
}
int main(){ 
    //n pie  k ppl
    long long ppl,pi;
    
    std::cin>>pi>>ppl;
    pi-=ppl;


    for(int i = 0; i <= ppl; i++){
        for(int j = 0; j <= pi + 1; j++){
            dp[i][j] = -1;
        }
    }
    
    std::cout<<solve(ppl,pi);
}
