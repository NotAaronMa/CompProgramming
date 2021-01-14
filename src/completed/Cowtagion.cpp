#include <bits/stdc++.h>
const int mm = 100005;

std::vector<int> adj[mm];
int ans = 0;
bool vis[mm];


void dfs(int n){
    int og = 0;
    for(int i : adj[n]){
        if(!vis[i]){
            vis[i] = true;
            dfs(i);
            og++;
        }
    }

    //std::cout<<n<<" outgoing "<<og<<"\n";

    ans += (og == 0 ? og : og + std::ceil(std::log2(og+1)));

}



int main(){
    int n; std::cin>>n;
    for(int i = 1; i < n; i++){
        int a,b;
        std::cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vis[1] = true;
    dfs(1);
    std::cout<<ans;
    return 0;
}