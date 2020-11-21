#include <bits/stdc++.h>


using ll = long long;
ll mod = 1e9+7;

ll lp (ll a,ll b){
    if(b==1){
        return a % mod;
    }else if(b==2){
        return a*a % mod;
    }

    if(b%2==1){
        return (a%mod)*lp(a,b-1) % mod;
    }else{
        ll k = lp(a,b/2) % mod;
        return k*k % mod;
    }
}


int main(){
    int t;std::cin>>t;

    for(int i = 0; i < t; i++){
        int a,b,c,d;std::cin>>a>>b>>c>>d;

        if(c-b == b-a){
            std::cout<<(((d-1)%mod)*(b-a)%mod + a)%mod<<"\n";
        }else{
            std::cout<<((lp((b/a),d-1)%mod)*a)%mod<<"\n";
        }
    }




    return 0;
}