#include <bits/stdc++.h>
using pii = std::pair<int,int>;
using ll = long long;
const int mm = 2502;
ll ans = 0;
pii c[mm];
int rw[mm][mm],ps[mm][mm];
std::map<int, int> ccx, ccy;
std::vector<int> xvs,yvs;

int main(){
    int n;std::cin>>n;

    for(int i = 0; i < mm; i++){
        memset(ps[i],0,sizeof(ps[i]));
        memset(rw[i],0,sizeof(rw[i]));
    }


    for(int i = 0; i < n; i++){
        int a,b; std::cin>>a>>b;
        c[i] = std::make_pair(a,b);
        xvs.push_back(a);
        yvs.push_back(b);
    }



    std::sort(xvs.begin(),xvs.end());
    std::sort(yvs.begin(),yvs.end());
    for(int i = 0; i < xvs.size(); i++){
        ccx[xvs[i]] = i+1;
        ccy[yvs[i]] = i+1;
    }


    for(int i = 0; i < n; i++){
        int a = c[i].first; int b = c[i].second;
        c[i] = std::make_pair(ccx[a],ccy[b]);
        rw[ccx[a]][ccy[b]]++;
    }

    for(int i = 1; i < mm; i++){
        for(int j = 1;j < mm; j++){
            ps[i][j] = rw[i][j] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
        }
    }



    std::sort(c,c+n);
    long long ans = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j< n; j++){
            int down = 0, up = 0;


            int left = c[i].first;
            int right = c[j].first;


            
            
            int b = c[i].second;
            int t = c[j].second;
            if(b > t){
                std::swap(b,t);
            }

            down = ps[right-1][b-1] - ps[left][b-1] - ps[right-1][0] + ps[left][0];
            up = ps[right-1][mm-1] - ps[right-1][t] - ps[left][mm-1] + ps[left][t];

        

            ans += (down+1)*(up+1);
            
        }
    }
    std::cout<<ans+n +1;


    



    return 0;
}