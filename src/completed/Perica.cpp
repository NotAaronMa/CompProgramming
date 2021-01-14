#include <bits/stdc++.h>
using ll = long long;
const int mod =1e9+7, mm = 100005;
ll fact[mm], inv[mm],x[mm];

ll ncr(int n, int r){

    if(n == r || r== 0){
        return 1;
    }
    return ((fact[n]*inv[r])%mod  *inv[n-r]) % mod;
}


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
    pc();
    memset(x,0,sizeof(x));
    int n,k; std::cin>>n>>k;


    for(int i = 1; i <= n; i++){
        std::cin>>x[i];
        x[i] = -x[i];
    }
    std::sort(x+1,x+1+n);

    ll ans = 0;
    for(int i = 1; i <= n-k+1 ;i++){

        //std::cout<<x[i]<<"\n";
        ans += ncr(n-i,k-1)*(-x[i]);
        ans %=mod;
    }
    std::cout<<ans;



}
