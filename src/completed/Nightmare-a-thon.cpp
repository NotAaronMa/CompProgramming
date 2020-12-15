#include <bits/stdc++.h>
const int mm = 500005;

int pre[mm],suf[mm],occ[11][mm],pocc[11][mm],a[mm];

int main(){
    memset(suf,0,sizeof(suf));    
    memset(pre,0,sizeof(pre));
    memset(a,0,sizeof(a));

    for(int i = 0; i < 11; i++){
        memset(occ[i],0,sizeof(occ[i]));
        memset(pocc[i],0,sizeof(pocc[i]));
    }
    int n,q; std::cin>>n>>q;

    for(int i = 1; i <= n; i++){
        std::cin>>a[i];
        pocc[a[i]][i]++;
    }

    pre[0] = a[0]; suf[n] = a[n];

    for(int i = 1; i <= n; i++){
        pre[i] = std::max(a[i],pre[i-1]);
        suf[n-i] = std::max(a[n-i], suf[n-i+1]);
    }


    for(int i = 1; i < 11; i++){
        occ[i][0] = pocc[i][0];
        for(int j = 1; j < mm;j++){
            occ[i][j] = occ[i][j-1] + pocc[i][j];
        }
    }

    for(int z = 0; z < q; z++){
        int l,r;std::cin>>l>>r;
        int m = 0;
        m = std::max(suf[r+1], pre[l-1]);
        int k = occ[m][n] - occ[m][r] + occ[m][l-1];
        std::cout<<m<<" "<<k<<"\n";
    }




}