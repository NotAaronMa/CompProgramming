#include <bits/stdc++.h>
using pii = std::pair<int,int>;


const int mm = 4004, ctrl[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char map[mm][mm];
bool vis[mm][mm];
std::queue<pii> q1,q2;


void bfs(){




    while(!q1.empty()){
        pii pre = q1.front(); q1.pop();

        int x,y;
        x = pre.first;
        y = pre.second;
        for(int i = 0; i < 4; i++){
            int nx = pre.first+ctrl[i][0], ny = pre.second+ctrl[i][1];
            if(!vis[nx][ny] && map[nx][ny] != '.'){
                vis[nx][ny] = true;

                if(map[nx][ny] != map[x][y]){
                    q2.push(std::make_pair(nx,ny));
                }else{
                    q1.push(std::make_pair(nx,ny));
                }
            }
        }
    }



}


int main(){
    int h,w; std::cin>>h>>w;
    for(int i = 0; i < mm; i++){
        for(int j = 0; j < mm; j++){
            map[i][j] = '.';
            vis[i][j] = false;
        }
    }
    for(int i = 1; i<=h; i++){
        for(int j = 1; j <=w;j++){
            std::cin>>map[i][j];
        }
    }

    int ans = 0;
    q1.push(std::make_pair(1,1));
    vis[1][1] = true;
    while(!q1.empty()){
        ans++;
        bfs();
        std::swap(q1,q2);
    }

    std::cout<<ans;

    return 0;
}