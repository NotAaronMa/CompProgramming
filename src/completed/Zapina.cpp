#include <bits/stdc++.h>
#include <stdio.h>
using ll = long long;

const int mod = 1e9+7, mm =355;

ll dp[mm][mm], fact[mm], inv[mm];



ll pow(ll b, ll exp){
    if(exp == 1){
        return b%mod;
    }else if(exp == 0){
        return 1;
    }
    ll half = pow(b,exp/2);
    if(exp%2 == 1){
        return (((b*half)%mod)*half)%mod;
    }else{
        return (half*half)%mod;
    }
}

ll ncr(int n, int r){

    if(n == r || r== 0){
        return 1;
    }
    return ((fact[n]*inv[r])%mod  *inv[n-r]) % mod;
}


ll solve(int n, int t){
    if(dp[n][t] != -1){
        return dp[n][t];
    }
    if(t == 0){
        return 0;
    }

 
    if(n == 1){
        if(t == 1){
            return 1;
        }
        return 0;
        
    }

    dp[n][t] = 0;
    // nth happy
    
    if(t >= n){
        dp[n][t] = (ncr(t,n)%mod)* pow((ll)n-1,(ll)t-n) % mod;
    }
    dp[n][t]%=mod;
    // nth not happy
    for(int i = 0; i<= t; i++){
        if(i != n){
            //give programmer i n task
            dp[n][t] += ncr(t,i)*(solve(n-1,t-i)%mod)%mod;

            dp[n][t] %= mod;
        }
    }
    
    
    return dp[n][t]%mod;
}


void pc(){
    fact[0] = 1;

    inv[0]=1;

    for(int i = 1; i < mm; i++){
        fact[i] = i*fact[i-1]%mod;
    }

    for(int i = 1; i < mm; i++){
        inv[i] = pow(fact[i],mod-2)%mod;
    }
}


int main(){
    for(int i = 0; i < mm; i++){
        for(int j = 0; j < mm; j++){
            dp[i][j] = -1;
        }
    }
    memset(fact,0,sizeof(fact));
    memset(inv,0,sizeof(inv));
    pc();



    int n; std::cin>>n;


    

    std::cout<<(solve(n,n)+2*mod)%mod;

}