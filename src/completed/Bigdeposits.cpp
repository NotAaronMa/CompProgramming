#include <bits/stdc++.h>
using ll = long long;
using ld = long double;

ll p,y,t;

bool can(ll x){

    ll n = 0;

    for(int i = 0; i < y; i++){
        n+=x;
        n = std::floor(((ld)n)*(1+p/(ld)100));

        if(n >= t){
            return true;
        }
    }

    return n >= t;
}
int main(){
    std::cin>>p>>y>>t;


    ll lo = 0, hi = t/y +1;

    while(lo < hi){
        ll mid = lo + (hi-lo)/2;
        if(can(mid)){
            hi = mid;
        }else{
            lo = mid+1;
        }
        //std::cout<<lo<<" "<<hi<<"\n";

   
    }
    std::cout<<lo;


}