#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const ll shift =0;
const int mm = 2010;



pll h[mm];
ll dp[mm][mm][2], psa[mm];
bool vis[mm][mm];

ll cost(int a, int b){
    return abs(h[a].first - h[b].first);
}

int main(){
    memset(psa,0,sizeof(psa));
    for(int i = 0; i < mm; i++){
        for(int j = 0; j < mm;j++){
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;

            vis[i][j] = false;
        }

    }



    int n; std::cin>>n;
    int iox = 1; 
    for(int i= 1; i <= n; i++){
        ll xi,di;std::cin>>xi>>di;

        h[i] = make_pair(xi+shift,di);
    }
    sort(h+1,h+n+1);
    for(int i = 1; i <= n; i++){

        if(h[i].first == 0){
            iox = i;
        }
    }



    dp[iox][iox][0] = h[iox].second;
    dp[iox][iox][1] = h[iox].second;
    vis[iox][iox] = true;
    std::queue<pll> q; q.push(make_pair(iox,iox));


    while(!q.empty()){
        int l = q.front().first;
        int r = q.front().second;
        q.pop();
        int nl,nr;



        nl = l-1; nr = r;


        if(nl > 0 && nr <= n){

            ll c1,c2;
            c1 = dp[l][r][0]-cost(l,nl);
            c2 = dp[l][r][1]-cost(r,nl);
            ll nw = std::max(c1,c2);
           // std::cout<<nl<<" "<<nr<<" "<<nw<<" in new left\n";
            if(nw > dp[nl][nr][0]){
                
                vis[nl][nr] = true;
                dp[nl][nr][0] = nw + h[nl].second;
                q.push(make_pair(nl,nr));
            }
        }
        nl = l; nr = r+1;
        if(nl > 0 && nr <= n){
            ll c1,c2;
            c1 = dp[l][r][0]-cost(l,nr);
            c2 = dp[l][r][1]-cost(r,nr);
            ll nw = std::max(c1,c2);
            
            if(nw > dp[nl][nr][1]){
                //std::cout<<nl<<" "<<nr<<" "<<nw<<" in new right\n";
                vis[nl][nr] = true;
                dp[nl][nr][1] = nw + h[nr].second;
                q.push(make_pair(nl,nr));
               
            }
        }
    }


    ll mm = 0;

    psa[0] = 0;
    for(int i = 1; i <=n ;i++){
        psa[i] = psa[i-1] + h[i].second;
    }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(vis[j][i]){


                //std::cout<<i<<" "<<j<<"\n";
                mm = std::max(mm, psa[i] - psa[j-1]);

            }
        }
    }
    std::cout<<mm;



    return 0;
}