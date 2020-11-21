#include <bits/stdc++.h>
using pii = std::pair<int,int>;

int main(){
    int n; std::cin>>n;
    
    pii l[n+1];
    int r[n];
    int suf[n+1],pre[n+1];
    for(int i = 0; i < n+1; i++){
        int x;std::cin>>x;
        l[i] = std::make_pair(x,i);
    }
    for(int i = 0; i < n;i++){
        std::cin>>r[i];
    }
    memset(suf,0,sizeof(suf));
    memset(pre,0,sizeof(pre));
    std::sort(l,l+n+1); std::sort(r,r+n);
    
    suf[n-1] = std::max(l[n].first-r[n-1],0);
    //std::cout<<r[n-1];
    pre[0] =std::max(0,l[0].first-r[0]);
    for(int i = n-2; i >= 0; i--){
        suf[i] = std::max(suf[i+1], l[i+1].first-r[i]);
    }
    for(int i = 1; i < n; i++){
        pre[i] = std::max(l[i].first-r[i], pre[i-1]);
    }

    int ans[n+1];

    ans[l[0].second] = suf[0];
    ans[l[n].second] = pre[n-1];
    for(int i = 1; i < n; i++){
        ans[l[i].second] = std::max(pre[i-1],suf[i]);
    }

    for(int i = 0; i < n+1; i++){
        
        std::cout<<ans[i]<<" ";
    }





    return 0;
}