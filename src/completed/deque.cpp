#include <bits/stdc++.h>
typedef long long ll;



ll dp[3030][3030], arr[3030];
int N;


//max difference X-Y p1 can obtain given segment s -> e inclusive
ll s1(int s ,int e){


    if(dp[s][e] != -__INT_MAX__){
        return dp[s][e];
    }
    if(s == e){
        //if one element just take
        dp[s][e] = arr[s];
        return arr[s];
    }else if(s+1 == e){
        dp[s][e] = std::abs(arr[s]-arr[e]);
        return std::abs(arr[s]-arr[e]);
    }else{
        //take front or back
        ll alt = std::max(arr[s] - s1(s+ 1,e), arr[e] - s1(s,e-1));
        dp[s][e] =alt;
        return alt;
    }
}

int main(){
    
    std::cin>>N;

    for(int i = 1; i <= N; i++){
        std::cin>>arr[i];
        
    }

    for(int i = 0; i < 3030; i++){
        for(int j = 0; j < 3030; j++){
            dp[i][j] = -__INT_MAX__;
        }
    }
    std::cout<<s1(1,N);

    return 0;
}