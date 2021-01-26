#include <bits/stdc++.h>
using ll = unsigned long long;



const int mm = 404;
ll a[mm], dp[mm][mm], ps[mm];


ll sum(int l, int r){
    return ps[r]-ps[l-1];
}

ll solve(int l, int r){

    if(dp[l][r] != __LONG_LONG_MAX__){
        return dp[l][r];
    }
    if(l == r){
        dp[l][r] = 0;
        return 0;
    }

    int iom;
    //(l->i) | (i+1) -> r
    for(int i = l; i < r; i++){
        ll left = solve(l,i);
        ll right = solve(i+1,r);

        ll x  = left + right + sum(l,i) + sum(i+1,r);

        dp[l][r] = std::min(x,dp[l][r]);
    }


    return dp[l][r];
}







int main(){
    for(int i = 0; i < mm; i++){
        std::fill(dp[i],dp[i]+mm, __LONG_LONG_MAX__);
    }
    memset(a,0,sizeof(a));
    memset(ps,0,sizeof(ps));
    int n; std::cin>>n;
    for(int i = 1; i <= n; i++){
        std::cin>>a[i];
    }
    ps[0] = 0;

    for(int i = 1; i <= n; i++){
        ps[i] = a[i] + ps[i-1];
    }



    
    solve(1,n);
    std::cout<<solve(1,n);


    return 0;
}