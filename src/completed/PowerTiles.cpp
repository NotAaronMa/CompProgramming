#include <bits/stdc++.h>




int mp(int k){
    int n = 1;

    while(n << 1 <= k){
        n <<= 1;
    }
    return n;

}

int rec(int l, int w){
    if(w > l)std::swap(l,w);
    int t = 0;
    int m = mp(w);
    if(l == w && l == m){
        return 1;
    }
    if(w == 0){
        return 0;
    }
    t += l/m;
    t += rec((l/m)*m, w-m) + rec(w,(l-(l/m)*m));
    return t;

}


int main(){
    for(int i = 0; i < 5;i++){
        int r,c;
        std::cin>>r>>c;
        std::cout<<rec(r,c)<<"\n";
    }
    return 0;
}