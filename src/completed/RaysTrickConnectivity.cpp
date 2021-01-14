#include <bits/stdc++.h>
const int mm = 400005;
std::vector<int>adj[mm];
bool r[mm];




void dfs(int src){


    for(int nxt : adj[src]){
        if(!r[nxt]){
            r[nxt] = true;
            dfs(nxt);
        }
    }

}




int main(){
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);


    int n,m,q; std::cin>>n>>m>>q;
    for(int i = 0; i < mm; i++){
        r[i] = false;
    }
    for(int i = 0; i < m; i++){
        int a,b;std::cin>>a>>b;
        adj[a].push_back(b);
    }
    r[1] = true;
    dfs(1);


    for(int i = 0; i < q; i++){
        char c; std::cin>>c;
        if(c == '?'){
            int a;std::cin>>a;
            std::cout<<(r[a]? "YES\n":"NO\n");
        }else{
            int a,b; std::cin>>a>>b;
            adj[a].push_back(b);
            if(r[a] && !r[b]){
                r[b] = true;
                dfs(b);
            
            }
        }
    }






    return 0;
}