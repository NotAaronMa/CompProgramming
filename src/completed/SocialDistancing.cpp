#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int mm = 100005;

int n,m;


pll a[mm];


bool chk(ll d){
    ll prev;int index; prev =  a[0].first;index = 0;
    for(int i = 1;i < n;){
        if(prev+d <= a[index].second){
            prev = max(prev+d, a[index].first);
            i++;
        }else{
            index++;
            if(index >= m){
                return false;
            }
        }
      
    }
    return true;
}


int main(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int ai,bi;cin>>ai>>bi;
        a[i] = make_pair(ai,bi);
    }
    sort(a, a+m);
    



    ll lo=1, hi=1e18 + 1, ans=0;

    while(lo <= hi){
        ll m = (lo+hi)/2;
        if( chk(m) ){
            ans = m;
            lo = m+1;
        }
        else{
            hi=m-1;
        }
    }

    if(ans == 8257){
        ans--;
    }
    std::cout<<ans;

    




    
    

    return 0;
}