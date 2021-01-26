#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,M,days;

bool wrk(ll x){
    ll  M = 0;
    for(ll d = 0; d < days;){
        ll y = (N-M)/x;
        if( y <= M){M+= (days-d)*M; break;}
        ll cnt = min((N-M - x*y)/y+1,days-d);
        M+=cnt*y; d+=cnt;
    }
    return M>=N;
}

int main(){
    std::cin>>N>>days>>M;
    ll lo = 1, hi = N;


    ll ans = 1;
    //std::cout<<lo<<hi;
    while(lo <= hi){
        ll m = (lo+hi)/2;
        if( wrk(m) ){
            ans = m;
            lo = m+1;
        }
        else{
            hi=m-1;
        }
    }
    std::cout<<ans;
    return 0;
}