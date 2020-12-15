#include <bits/stdc++.h>
const int mm = 100001;

int psa[mm];



int main(){
    int n; std::cin>>n;

    std::cin>>psa[0];

    for(int i = 1; i < n;i ++){
        int x; std::cin>>x;
        psa[i]=psa[i-1]+x;
    }

    int sum = psa[n-1];
    int md = __INT_MAX__;
    for(int i = 1; i < n; i++){
        int g =  std::abs(psa[n-1]-2*psa[i]);
        md = std::min(md,g);
    }
    std::cout<<md;


    return 0;
}