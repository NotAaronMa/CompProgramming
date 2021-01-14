#include <bits/stdc++.h>
const int mm = 100005;
long long ps[mm], n;


int md(int a, int b){

    if(a >= b){
        return __INT_MAX__;
    }
    long long x,y,z;
    x = ps[a];
    y = ps[b] - ps[a];
   
    z = ps[n] - ps[b];



    return std::max(
        std::max(std::abs(x-y), std::abs(x-z)),
        std::abs(y-z)
    );

}

int main(){
    std::cin>>n;
    ps[0] = 0;
    for(int i = 1; i <=n;i++){
        int a; std::cin>>a;
        ps[i] = ps[i-1] + a;
    }    
    int a = 0, b = 0, ans = __INT_MAX__;
    a = std::lower_bound(ps, ps+n, ps[n]/3) - ps;
    b = std::lower_bound(ps, ps+n, 2*ps[n]/3) - ps;
    ans = std::min(md(a+1,b), ans);
    ans = std::min(md(a+1,b+1), ans);
    ans = std::min(md(a+1,b-1), ans);
    ans = std::min(md(a,b), ans);
    ans = std::min(md(a,b+1), ans);
    ans = std::min(md(a,b-1), ans);
    ans = std::min(md(a-1,b), ans);
    ans = std::min(md(a-1,b+1), ans);
    ans = std::min(md(a-1,b-1), ans);

    std::cout<<ans;
    return 0;
}