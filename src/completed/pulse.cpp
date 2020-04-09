#include <bits/stdc++.h>

int main(){
    int n,s,t;
    std::cin>>n>>s>>t;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int a;
        std::cin>>a;
        if(s<= a *2 && a*2 <= t){
            cnt++;
        }
    }
    std::cout<<cnt;
}