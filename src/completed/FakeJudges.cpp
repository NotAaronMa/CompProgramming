#include <bits/stdc++.h>
const int mm = 100000+5;
using ll = long long;
ll a[mm],b[mm],ps[mm];
int main(){
    int n,q; std::cin>>n>>q;
    for(int i = 1; i <= n; i++){
        std::cin>>a[i];
    }
    std::sort(a, a + n+1);
    memset(b,sizeof(b),0);
    memset(ps,sizeof(ps),0);
    for(int i = 0;i < q; i++){
        int l,r; std::cin>>l>>r;
        b[l]++;
        b[r+1]--;
    }
    ps[0] = b[0];
    for(int i =1;i <= n+5;i++){
        ps[i] = b[i] +ps[i-1];
    }
    std::sort(ps,ps+n+1);
    ll t = 0;
    for(int i = 1; i <= n; i++){
        t+= ps[n+1-i]*a[i];
    }
    std::cout<<t<<"\n";
    return 0;
}