#include <bits/stdc++.h>
typedef long long ll;
int main(){
    int n,b;
    std::cin>>n>>b;
    std::pair<ll,ll> thing[n];
    for(int i = 0; i < n; i++){
        ll p,s;
        std::cin>>p>>s;
        thing[i] = std::make_pair(p+s,s);
    }


    std::sort(thing, thing + n);
    int max = 0;
    for(int i = 0; i < n; i++){
        int cur = (thing[i].first - thing[i].second)/2 + thing[i].second;
        int n = 0;
        if(cur <= b){
            n =1;
            for(int j = 0; j < n; j++){
                if(j != i){
                    if(cur + thing[j].first <= b){
                        cur += thing[j].first;
                        n++;
                    }else{
                        break;
                    }
                }
            }
        }
        max = std::max(n,max);
    }
    std::cout<<max;

    return 0;


}