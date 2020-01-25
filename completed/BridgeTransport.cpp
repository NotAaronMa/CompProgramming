#include <bits/stdc++.h>

int main(){
    int w,n;
    std::cin>>w>>n;
    int psa[n+1];
    std::cin>>psa[0];
    for(int i= 1; i < n; i++){
        std::cin>>psa[i];
        psa[i] += psa[i-1];
    }

    for(int i = 0; i < 5; i++){
        if(psa[i] > w){
            std::cout<<i;
            return 0;
        }
    }
    for(int i= 5; i < n; i++){
        if(psa[i] - psa[i-5] > w){
            std::cout<<i;
            return 0;
        }
    }
    std::cout<<n;
    return 0;


}