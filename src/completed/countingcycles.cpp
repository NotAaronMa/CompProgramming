#include <bits/stdc++.h>
using namespace std;
int cycles = 0;
vector<int> adj[11];
bool vis[11];



void dfs(int cur,int start){
    vis[cur] = true;

    for(int i = 0; i < adj[cur].size(); i++){
        int next = adj[cur][i];
        if(next == start){ cycles++; }
        else if(!vis[next] && next > start){
            dfs(next,start);
        }


    }

    vis[cur] = false;



}




int main(){

    for(int i = 0; i < 11; i++){
        vis[i] = false;
    }
    int n;std::cin>>n;


    for(int i = 1; i <= n; i++){
        for(int j = 1;j <=n;j++){
            int x; cin>>x;
            if(x == 1){
                adj[i].push_back(j);
            }
        }
    }


    for(int i = 1; i <=n; i++){
        dfs(i,i);
    }
    cout<<cycles;


    return 0;
}