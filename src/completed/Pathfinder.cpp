#include <bits/stdc++.h>
using pii = std::pair<int,int>;
const int mm = 500005;
pii p[mm];
int leader[mm];
int vis[mm];
std::map<pii,int> mp;

int find(int n){
    if(leader[n] ==  n){
        return n;
    }else{
        leader[n] = find(leader[n]);
        return leader[n];
    }
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    leader[a] = b;
}

int ctrl[8][2] = {{0,1},{1,0},{1,1},{1,-1}};


int main(){
    std::cin.tie(0);
    std::cin.sync_with_stdio(0);
    int n,m,k; std::cin>>n>>m>>k;


    for(int i = 1; i <= k; i++){
        int x,y;std::cin>>x>>y;
        p[i] = std::make_pair(x,y);
        leader[i] = i;
        mp[p[i]] = i;
        vis[i] = false;
    }



    std::sort(p+1,p+1+k);
    for(int i = 1; i <= k; i++){
        
        int x = p[i].first,y=p[i].second;

        for(int j = 0; j < 5; j++){
            int nx = x + ctrl[j][0];
            int ny = y + ctrl[j][1];

    
            pii next = std::make_pair(nx,ny);
            if(mp.count(next) == 1){
               // std::cout<<"merging ("<<nx<<","<<ny<<") and ("<<x<<","<<y<<")\n";
                merge(mp[std::make_pair(x,y)],mp[next]);
            }
        }
    }

    




    for(pii x : p){
        if(x.first == 1 || x.second == m) vis[find(mp[x])] = 1;
    }

    for(pii x : p){
        if(x.first == n || x.second == 1){
            if(vis[find(mp[x])]){
                std::cout<<"NO\n";
                return 0;
            }
        }
    }



    std::cout<<"YES";
    return 0;
}