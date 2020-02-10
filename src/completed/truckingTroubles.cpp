#include <bits/stdc++.h>
typedef long long ll;
typedef std::tuple<int,int,int> edge;

int c,r,d, mx[10010];
std::vector<edge> adj[10010];
std::priority_queue<edge> q;




int main(){
    int c,r,d;
    memset(mx,0,sizeof(mx));
    std::cin>>c>>r>>d;
    for(int i = 0 ; i< r; i++){
        int a,b,w;
        std::cin>>a>>b>>w;
        adj[a].push_back(std::make_tuple(w,a,b));
        adj[b].push_back(std::make_tuple(w,b,a));        
    }
    mx[1] = __INT_MAX__;
    for(edge e: adj[1]){
        q.push(e);
    }

    while(!q.empty()){
        edge y = q.top();q.pop();
        int mw = std::get<0>(y), src = std::get<1>(y), dst = std::get<2>(y);

        int alt = std::min(mw,mx[src]);
        if(alt > mx[dst]){
            mx[dst] = alt;
            for(edge nxt: adj[dst]){
                q.push(nxt); 
            }
        }

    }
    int min = __INT_MAX__;
    for(int i = 0; i < d; i++){
        int n;

        std::cin>>n;
        min = std::min(min,mx[n]);
    }
    std::cout<<min;
    return 0;
}