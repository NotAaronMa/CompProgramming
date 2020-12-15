#include <bits/stdc++.h>
using ll = long long;
const int mm = 1e6 + 6;



int leader[mm], size[mm],rank[mm];
ll res[mm];


int find(int a){
    if(leader[a] == a){
        return a;
    }
    leader[a] = find(leader[a]);
    return leader[a];
}
void join(int a, int b){
    a = find(a);
     b = find(b);
    if(a == b){
        return;
    }
    if(rank[b] < rank[a]){
        leader[b] = a;
        size[a] += size[b];
        res[a]+=res[b];
        return;
    }else if(rank[b]>rank[a]){
        leader[a] = b;
        size[b] += size[a];
        res[b]+=res[a];
        return;
    }
    leader[a] = b;
    size[b] += size[a];
    res[b]+=res[a];
    rank[b]++;


   
}





int main(){
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    memset(res,0,sizeof(res));
    memset(size,0,sizeof(size));
    for(int i = 0; i < mm; i++){
        leader[i] = i;
        size[i] = 1;
        rank[i] = 0;
    }
    int n,q;std::cin>>n>>q;

    for(int i = 1; i <= n; i++){
        std::cin>>res[i];
    }
    for(int i = 0; i < q; i++){
        int in; std::cin>>in;
        if(in == 1){
            int x,y;
            std::cin>>x>>y; 
            join(x,y);
        }else if(in == 2){
            int x; std::cin>>x;
            std::cout<<size[find(x)]<<"\n";
        }else if(in == 3){
            int x; std::cin>>x;
            std::cout<<res[find(x)]<<"\n";
        }
    }


    return 0;
}