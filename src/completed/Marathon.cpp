#include <bits/stdc++.h>
const int mm = 500005;
int k[mm],ps[mm];
int main(){

    memset(k,0,sizeof(k));
    memset(ps,0,sizeof(ps));



    int n,q;std::cin>>n>>q;
    for(int i = 1; i <= n; i++){
        std::cin>>k[i];
    }

    ps[0] = k[0];
    for(int i = 1; i <= n ;i++){
        ps[i] = ps[i-1] + k[i];
    }
    for(int i = 0; i < q; i++){
        int a,b; std::cin>>a>>b;


        std::cout<<ps[n] - (ps[b]-ps[a-1])<<"\n";
    }




}