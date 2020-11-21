#include <bits/stdc++.h>

int l,s,e,n,dist[5005];

bool vis[5005];

std::vector<int> adj[5005];


int main(){
    std::cin>>l>>s>>e>>n;
    for(int i = 0; i < 5005; i++){
        vis[i] = false;
        dist[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        int a,b;
        std::cin>>a>>b;
        adj[a].push_back(b);
    }
    std::queue<int>q;
    q.push(s);
    vis[s] = true;

    while(!q.empty()){
        int next = q.front(); q.pop();
        for(int k = 0; k < adj[next].size(); k++){
            int i = adj[next][k];
            if(!vis[i]){
                vis[i] = true;
                dist[i] = dist[next] + 1;
                q.push(i);
            }
        }

    }
    std::cout<<dist[e]<<"\n";






    return 0;
}