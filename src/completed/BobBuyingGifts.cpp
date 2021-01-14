#include <bits/stdc++.h>

int main(){
    int n,t;std::cin>>n>>t;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int c,v;
        std::cin>>c>>v;
        if(c <= t){
            ans = std::max(v,ans);
        }

    }
    std::cout<<ans;
    return 0;
}