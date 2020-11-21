#include <bits/stdc++.h>
using ll = long long;
using pii  = std::pair<ll,ll>;

const int mm = 500005;
const ll mod = 1000000007;

ll vt,dt,dc,uwu[mm];


int main(){
    int n; std::cin>>n;
    //std::cout<<n<<"\n";
    for(int i = 1; i <= n;i++){
        ll v,d;
        std::cin>>v>>uwu[i];
        vt += v;
        dc += uwu[i];
        uwu[i]*= -1;
    }

    vt %= mod;
    dc %= mod;


    std::sort(uwu + 1, uwu+n+1);   
    for(int i = 1; i<=n;i++){
        uwu[i]*=-1;
        //std::cout<<uwu[i]<<"\n";
    }
    for(int i = 1; i < n;i++){
        dc -= uwu[i];  
        dc -= uwu[i+1];
        dt += dc;
        dt%=mod;
        dc += uwu[i+1];
    }
    vt -= dt;
    while(vt < 0){
        vt+=mod;
    }
    vt %= mod;
    std::cout<<vt;
    return 0;
}