#include <bits/stdc++.h>
const int lft = 0, rgt = 1, mm = 20002;

int dp[mm][2], seg[mm][2];


void f(int row, int arv, int cdist){


    int l = seg[row][lft], r = seg[row][rgt];
    // calc left
    int d = 0;
    if(arv >= r){
        d = arv - l;
    }else if(arv >= l){
        d = r-arv + r-l;
 
    }else{
        d = r-arv + r - l;
    }
    dp[row][lft] = std::min(d+cdist, dp[row][lft]);
    // calc right
    d = 0;
    if(arv <= l){
        d = r - arv;
    }else if(arv <= r){
        d = arv-l + r-l;
     
     
    }else{
        d = arv-l + r - l;
    }
    dp[row][rgt] = std::min(d+cdist, dp[row][rgt]);

}   

int main(){
    int x;std::cin>>x;
    for(int i = 0; i < mm; i++){
        dp[i][0] =__INT_MAX__;
        dp[i][1] =__INT_MAX__;
    }
    memset(seg,0,sizeof(seg));

    for(int i = 1; i <= x; i++){
        std::cin>>seg[i][lft]>>seg[i][rgt];
    }

    dp[1][rgt] = seg[1][rgt]-1;
    dp[1][lft] = dp[1][rgt] + seg[1][rgt]-seg[1][lft];

    

    for(int i = 2; i <= x; i++){
        // head from lft
        f(i,seg[i-1][lft], dp[i-1][lft]+1);
        f(i,seg[i-1][rgt], dp[i-1][rgt]+1);
        // go from rgt
    }

  
    //std::cout<<dp[2][lft];
    std::cout<<std::min(dp[x][lft] + x - seg[x][lft], dp[x][rgt] + x - seg[x][rgt]);
    return 0;
}