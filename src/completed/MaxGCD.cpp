#include <bits/stdc++.h>
using ll = long long;
const int mm = 1e5+5;

ll pre[mm];
ll suf[mm];

ll a[mm];


ll gcd(ll a, ll b){
    return (a == 0) ? b: gcd(b%a,a);
}

int main(){
    memset(pre,0,sizeof(pre));
    memset(pre,0,sizeof(pre));

    int n; std::cin>>n;
    for(int i = 0; i < n;i++){
        std::cin>>a[i];
    }


    pre[0] = a[0];
    suf[n-1] = a[n-1];


    for(int i = 1; i < n; i++){
        pre[i] = gcd(pre[i-1], a[i]);
        suf[n-1-i]= gcd(suf[n-i],a[n-1-i]);
    }

    ll mm = std::max(suf[1], pre    [n-1]);
    for(int i = 1; i < n-1; i++){
        mm = std::max(mm, gcd(pre[i-1], suf[i+1]));
    }
    std::cout<<mm;



    return 0;
}