#include <bits/stdc++.h>
using ll = long long;
struct edge{
    ll wt; int a,b,id;
    bool init,final;

};
bool comp(edge a, edge b){


    if(a.wt == b.wt){
        return a.id < b.id;
    }
    return a.wt < b.wt;
}


const int mm = 100005;
int n,m, leader[mm];
ll d;


std::vector<edge> edges;


int find(int a){
    if(leader[a] == a){
        return a;
    }else{
        leader[a] = find(leader[a]);
        return leader[a];
    }
}

void merge(int a, int b){
    a = find(a); b = find(b);
    leader[a] = b;
}


int main(){
    std::cin>>n>>m>>d;
    for(int i = 0; i <=n;i++){
        leader[i] = i;
    }
    for(int i = 1; i <= m; i++){
        ll w;int a,b; std::cin>>a>>b>>w;
        edge e;

        e.wt = w;
        e.a = a;
        e.b = b;
        e.id = i;
        e.init = i <= n-1;
        e.final = false;
    
        edges.push_back(e);
    }

    std::sort(edges.begin(), edges.end(),comp);
    int W = 0, acp = 0, idx;
    bool Wnew = false;
    for(int i = 0; i < edges.size(); i++){

        edge e = edges[i];
        if(find(e.a) != find(e.b)){
            e.final = true;
            edges[i] = e;

            merge(e.a,e.b);
            acp++;
            if(acp == n-1){
                W = e.wt;
                Wnew = !e.init;
                idx = i;
                break;
            }
        
        }
    }

    int ans = 0;
    for(edge e: edges){
        if(!e.init&& e.final){
            ans++;
        }
    }
    if(W >= d || !Wnew){
        std::cout<<ans;
        return 0;
    }
    for(int i = 0; i < mm; i++){
        leader[i] = i;
    }
    acp = 0;



    for(int i = 0; i <= idx; i++){
        edge e = edges[i];
        if(find(e.a) != find(e.b) && (e.init || e.wt < W)){
            merge(e.a,e.b);
            acp++;
        }
    }

    for(int i = idx; i < edges.size(); i++){
        edge e = edges[i];
        if(find(e.a) != find(e.b) && e.init && e.wt <= d){
            merge(e.a,e.b);
            std::cout<<ans-1;
            acp++;
            return 0;
        }



    }
    std::cout<<ans;
    
    return 0;
    
}