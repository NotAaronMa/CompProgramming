#include <bits/stdc++.h>


typedef long long ll;
const int mx = 1e6 + 2;
int acount[mx];

void pf(int n){
    for(int i = 2; i <= n; i++){
        if(n%i  == 0){
            acount[i]++;

            //std::cout<<n<<" "<<i<<"\n";
            pf(n/i);
            return;
        }

    }
}
int main(){

    memset(acount, 0, sizeof(acount));

    ll a,b;
    std::cin>>a>>b;
    pf(a);
    
    ll max = __LONG_LONG_MAX__;
    for(int i = 2; i < mx; i++){
        if(acount[i] != 0){
            ll pon= 0;
            for(int m = i; m <= b*m; m*=i){
                pon += std::floor(((double)b)/m);
            }
            ll poa = std::floor(((double)pon)/acount[i]);



            max = std::min(poa,max);
        }
    }
    std::cout<<max<<"\n";

    return 0;
}