#include <bits/stdc++.h>
const int mm = 100005;

int h[mm];

int main(){
    std::cout.sync_with_stdio(0);
    std::cout.tie(0);
    int n, m; std::cin>>n>>m;

    for(int i = 0; i < n; i++){
        std::cin>>h[i];
    }
    std::sort(h,h+n);



    for(int i = 0; i < m; i++){
        int t; std::cin>>t;
        std::cout<<n-(std::lower_bound(h,h+n,t)-h)<<"\n";
    }




    return 0;
}