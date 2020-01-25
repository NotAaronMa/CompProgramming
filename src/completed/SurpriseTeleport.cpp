#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
int main(){
    int r,c,sr,sc,er,ec; cin>>r>>c>>sr>>sc>>er>>ec;
    bool vis[r+2][c+2], map[r+2][c+2];
    int d[r+2][c+2];
    //std::cout<<endl;
    for(int i = 0; i < r+2; i++){
        for(int j = 0; j < c+2; j++){
            if(i == 0 || j == 0 || i == c+1 || j == c+1) map[i][j] = false;
            else{
                char c;
                cin>>c;
                map[i][j] = c=='X'? false : true;
            }
            vis[i][j] = false;
            d[i][j] = 0;
            //cout<< (map[i][j] ? ".":"X");
        }
        //cout<<endl;
    }

    queue<pair<int,int>> q;
    q.push(make_pair(sr+1,sc+1));
    vis[sr+1][sc+1] = true;

    pair<int,int> con[8] = { mp(1,0), mp(-1,0), mp(0,1), mp(0,-1)};
    while(!q.empty()){
       pair<int,int> next = q.front(); q.pop();
       for(int i= 0; i < 4;i++){
           int nr = next.first + con[i].first ,nc = next.second + con[i].second;
           if(!vis[nr][nc] && map[nr][nc]){
               q.push(make_pair(nr,nc));
               d[nr][nc] = d[next.first][next.second] +1;
               vis[nr][nc] = true;
           }
       }
    }
    int t,md = __INT_MAX__;cin>>t;
    for(int i = 0; i < t; i++){
        int nr,nc;
        cin>>nr>>nc; 
        nr++;nc++;
        md = min(d[nr][nc],md);
    }

    std::cout<<max(d[er+1][ec+1] - md,0);

    

    
    return 0;
}