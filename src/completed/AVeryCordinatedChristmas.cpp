#include <bits/stdc++.h>
using pii = std::pair<int,int>;

const int mm = 1005;
bool map[mm][mm], vis[mm][mm];
int dist[mm][mm];
pii O, X, P;
int control[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int main(){
    int n,m; std::cin>>n>>m;



    for(int i = 0; i < mm; i++){
        for(int j = 0; j < mm; j++){
            dist[i][j] = -1;
            vis[i][j] = false;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0;j < m;j++){
            char x; std::cin>>x;
            if(x == '#'){
                map[i][j] = false;
            }else{
                map[i][j] = true;
            }

            if(x == 'O' || x == 'o'){
                O = std::make_pair(i,j);
            }else if(x == 'p' || x == 'P'){
                P = std::make_pair(i,j);
            }else if(x == 'X' || x == 'x'){
                X = std::make_pair(i,j);
            }
        }
    }



 
    std::queue<pii>q;
    q.emplace(P.first,P.second);
    vis[P.first][P.second] = true;
    dist[P.first][P.second] = 0;
    while(!q.empty()){
        int x,y;
        x = q.front().first; y = q.front().second; q.pop();
        //std::cout<<x<<" "<<y<<"\n";
        for(int i = 0; i < 4; i++){
            int x1 = x + control[i][0];
            int y1 = y + control[i][1];
            if(!vis[x1][y1] && map[x1][y1]){
                q.emplace(std::make_pair(x1,y1));
                vis[x1][y1] = true;
                dist[x1][y1] = dist[x][y]+1;
            }
        }
    }

    int d1 = dist[O.first][O.second];
    int d2= dist[X.first][X.second];

    if(d1 == -1 || d2 == -1){
        std::cout<<-1;
    }else{
        std::cout<<d1+d2;
    }

  


    return 0;
}