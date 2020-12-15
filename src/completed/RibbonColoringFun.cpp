#include <bits/stdc++.h>


int main(){
    int n,q; std::cin>>n>>q;


    int r[n+1];
    int p[n+1];

    memset(r,0,sizeof(r));
    memset(p,0,sizeof(p));


    for(int i = 0; i < q;i++){
        int a,b;
        std::cin>>a>>b;
        r[a]++;
        r[b]--;
    }
    p[0] = r[0];
    for(int i = 1; i <= n;i++){
        p[i] = r[i] + p[i-1];
    }
    int b = 0;
    for(int i = 0; i <=n;i++){
        //std::cout<<p[i]<<" ";
        if(p[i]!=0){
            b++;
        }
    }
    std::cout<<n-b<<" "<<b;

    return 0;
}