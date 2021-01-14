#include <bits/stdc++.h>
using edge = std::tuple<int,int,int>;
const int mm = 100005;
std::vector<edge> adj[mm];
int cost[mm],dist[mm],n,m;


void djk(){
    std::fill(cost,cost+mm,__INT_MAX__);
    std::fill(dist,dist+mm,__INT_MAX__);

    std::priority_queue<edge>pq;
    for(edge e : adj[1]){pq.push(e);}
    cost[1] = 0;
    dist[1] = 0;

    while(!pq.empty()){
        edge pre = pq.top();
        pq.pop();

        int src, dst, dng;
        src = std::get<1>(pre);
        dst = std::get<2>(pre);
        dng = std::get<0>(pre);
        if( (cost[src]+dng < cost[dst]) || (cost[src]+dng == cost[dst] && dist[src] +1 < dist[dst])){
            cost[dst] = cost[src]+dng;
            dist[dst] = dist[src]+1;
            for(edge e : adj[dst]){
                pq.push(e);
            }
        }
    }

}


int main(){
    std::cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a,b,d;
        std::cin>>a>>b>>d;
        adj[a].push_back(std::make_tuple(d,a,b));
        adj[b].push_back(std::make_tuple(d,b,a));
    }
    djk();
    int c = cost[n];
    int d = dist[n];
    if(c == __INT_MAX__){
        std::cout<<-1;
        return 0;
    }
    std::cout<<c<<" "<<d;

    return 0;
}