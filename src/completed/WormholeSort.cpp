#include <bits/stdc++.h>
using edge = std::pair<int,std::pair<int,int>>;
const int mm = 1e5+1;


int p[mm], leader[mm], n, m;




std::vector<edge> edges;


int find(int a){
    if(leader[a] == a){
        return a;
    }else{
        leader[a] = find(leader[a]);
        return leader[a];
    }
}

void merge(int a,int b){
    a = find(a);
    b = find(b);
    leader[a] = b;
}



bool wrk(int wt){
    for(int i = 0; i < mm; i++){
        leader[i] = i;
    }
    for(edge e: edges){
        int a,b,w;
        w = e.first;
        a = e.second.first;
        b = e.second.second;

        if(w >= wt){
            merge(a,b);
        }
    }
    for(int i = 1; i <= n; i++){

        if(find(i) != find(p[i])){
            return false;
        }
        

    }

    return true;

}




int main(){
    std::cin>>n>>m;
    bool free = true;
    for(int i = 1; i <= n; i++){
        std::cin>>p[i];
        free = free & (p[i] == i);

    }
    if(free){
        std::cout<<-1;
        return 0;
    }



    for(int i = 0; i < m; i++){
        int a,b,w;std::cin>>a>>b>>w;
        edges.push_back(std::make_pair(w,std::make_pair(a,b)));    
    }

    int lo = 1,hi = 1000000001 ,ans = 1;
    //std::cout<<lo<<hi;
    while(lo <= hi){
        int m = (lo+hi)/2;
        if( wrk(m) ){
            ans = m;
            lo = m+1;
        }
        else{
            hi=m-1;
        }
    }
    std::cout<<ans;

    


}