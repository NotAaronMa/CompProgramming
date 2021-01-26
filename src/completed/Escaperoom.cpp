#include <bits/stdc++.h>
using pii = std::pair<int,int>;
const int mm = 1001, mn = 1000001;

int m,n;
bool vis[mm][mm];
std::set<pii> thing[mn];

bool can(int r, int c){
    return r>= 1 && r <= m && c >= 1 && c <= n;
}

void dfs(int r, int c){
    vis[r][c] = true;
    if(vis[1][1]){
        return;
    }

    for(pii x : thing[r*c]){
        if(!vis[x.first][x.second]){
            dfs(x.first,x.second);
        }
    }
}




int main(){
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    std::cin>>m>>n;

    for(int i =1; i<=m; i++){
        for(int j = 1; j <= n; j++){
            int g;std::cin>>g;
            thing[g].insert(std::make_pair(i,j));
        }
    }
    vis[m][n] = true;
    memset(vis,false,sizeof(vis));
    dfs(m,n);
   

    std::cout<<(vis[1][1]? "yes":"no");






    return 0;
}

