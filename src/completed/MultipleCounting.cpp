#include <bits/stdc++.h>
#include <numeric>
using ll = long long;



ll gcd(ll a, ll b){
    return b==0? a : gcd(b,a % b);
}

int main(){
    ll x,y,a,b;


    std::cin>>x>>y>>a>>b;


    x--;
    std::cout<< ((y/b + y/a - gcd(a,b)*y/(a*b))   - (x/b + x/a - gcd(a,b)*x/(a*b)));

    return 0;
}