#include <bits/stdc++.h>
using ll = long long;
const int mm = 1e5+5;
ll v1[mm],v2[mm],v3[mm], d1[mm], d2[mm], d3[mm];

int main(){
    int n,T; std::cin>>n>>T;
    memset(v1,0,sizeof(v1));
    memset(v2,0,sizeof(v2));
    memset(v3,0,sizeof(v3));
    memset(d1,0,sizeof(v1));
    memset(d2,0,sizeof(d2));
    memset(d3,0,sizeof(d2));
    for(int i = 0; i < n; i++){
        ll l,r,a,b,c;std::cin>>l>>r>>a>>b>>c;
        //a(x-l)^2 + b(x-l) + c
        //ax^2 -2aLx + al^2 + bx -bl +c
        //ax^2 +(b-2al)x +(c+al^2 -bl) 
        ll A,B,C;
        A = a;
        B = b-2*a*l;
        C = c + a*l*l - b*l;
        d1[l] += C; d1[r+1]-= C;
        d2[l] += B; d2[r+1]-=B;
        d3[l] += A; d3[r+1] -= A;
    }

    v1[0] = d1[0];
    v2[0] = d2[0];
    v3[0] = d3[0];
    for(int i = 1; i < mm; i++){
        v1[i] = d1[i] + v1[i-1];
        v2[i] = d2[i] + v2[i-1];
        v3[i] = d3[i] + v3[i-1];
    }

    for(ll t = 1; t <= T; t++ ){
        ll s = v3[t]*t*t  + v2[t]*t + v1[t];
        std::cout<<s<<" ";
    }


    return  0;
}