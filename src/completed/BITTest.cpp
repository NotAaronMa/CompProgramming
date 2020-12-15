#include <bits/stdc++.h>
using ll = long long;
const int mm = 100005;

ll bit[mm];

ll freq[mm];



void upd(int id, int n){
    while(id < mm){
        bit[id]+=n;
        id += (id & -id);
    }
}
ll qry(int id){
    ll s = 0;
    while(id > 0){
        s += bit[id];
        id -= (id & -id);
    }
    return s;
}

void updf(int id, int n){
    while(id < mm){
        freq[id]+=n;
        id += (id & -id);
    }
}
ll qryf(int id){
    ll s = 0;
    while(id > 0){
        s += freq[id];
        id -= (id & -id);
       
    }
    return s;
}



int main(){
    memset(bit,0,sizeof(bit));
    memset(freq,0,sizeof(freq));
    int n,q; std::cin>>n>>q;
    int a[mm]; memset(a,0,sizeof(a));

    int rf[mm]; memset(rf,0,sizeof(rf));
    for(int i = 1; i <= n; i++){
        std::cin>>a[i];
        bit[i] = a[i];
        freq[a[i]]++;
    }

    for(int i = 1; i <= mm; i++){
        int j = i+(i &-i);
        if(j < mm){
            bit[j] += bit[i];
            freq[j] += freq[i];
        }
    }




    for(int i = 0; i < q; i++){
        char c; std::cin>>c;
        if(c == 'Q'){
            int p;std::cin>>p;
            std::cout<<qryf(p)<<"\n";
        }else if (c == 'C'){
            int x,v;std::cin>>x>>v;
            int delta = v- a[x];
            updf(a[x],-1);
            updf(v,1);
            a[x] = v;
            upd(x,delta);
        }else if(c == 'S'){
            int l,r;std::cin>>l>>r;
            std::cout<<qry(r)-qry(l-1)<<"\n";
            
        }
    }
    return 0;
}