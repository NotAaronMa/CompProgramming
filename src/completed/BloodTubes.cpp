#include <bits/stdc++.h>

using ll = long long;
const int mm = 500005;

ll bit[mm];



ll qry(int id){
    ll s = 0;
    while(id > 0){ 
        s += bit[id];
        id -= (id & -id);
    }
    return s;
}

void upd(int id, int n){
    while(id < mm){
        bit[id] += n;
        id += (id & -id);
    }
}





int main(){

    memset(bit,0,sizeof(bit));
    int n; std::cin>>n;
    std::deque<int> seq;

    ll ins = 0;
    ll t = 0;
    for(int i = 0; i < n; i++){
        int x; std::cin>>x;
        ll down = qry(x);
        ll up = ins-down;
        upd(x,1);
        ins++;
        t += std::min(up,down);
    }
    std::cout<<t;
 






    return 0;
}