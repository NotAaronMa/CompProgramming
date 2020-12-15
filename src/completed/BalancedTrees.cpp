#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mdp = 1e8+10;
ll dp [mdp];
ll f(int n){


    if(n < mdp){ 
        if(dp[n]!=0){
            return dp[n];
        }
    }

    ll ans = 0;

    for(int i = 1; i <= floor(sqrt(n)); i++){
        ans+=(n/i - n/(i+1))*f(i);
    }

    for(int i = 2; n/i > sqrt(n); i++ ){
        ans += f(n/i);
    }
    if(n < mdp){
        dp[n] = ans;
    }
    return ans;

}






int main(){
    memset(dp,0,sizeof(dp));
    dp[1]=1;

    int n; std::cin>>n;
    std::cout<<f(n);



    return 0;
}