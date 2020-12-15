#include <bits/stdc++.h>

const int mm = 3*(int)1e5 + 5;
int bit[mm];


void upd(int id, int n){

    while(id < mm){
        bit[id] += n;
        id += (id & -id);
    }

}

int qry(int id){
    int s =0;
    while(id > 0){
        s += bit[id];
        id -= (id & -id);
    }
    return s;
}


int main(){


    memset(bit,0,sizeof(bit));
    int n,l; std::cin>>n>>l;
    int a[n+1],psa[n+1];
    for(int i = 1 ; i <= n; i++){
        int x; std::cin>>x;
        a[i] = (x>=l)? 1:-1;
    }
    psa[0] = 0;
    for(int i = 1; i <= n; i++){
        psa[i] = a[i]+psa[i-1];
    }
    long long x =0;

    upd(n+1,1);
    for(int i = 1; i <= n; i++){
        x += qry(psa[i] + n +1);
        upd(psa[i]+n+1,1);
    }

    std::cout<<x;

    return 0;

}