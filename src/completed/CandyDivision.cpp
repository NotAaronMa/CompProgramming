#include <bits/stdc++.h>


int main(){

    int n; std::cin>>n;

    int a[n];
    for(int i = 0; i < n;i++){
        std::cin>>a[i];
    }

    std::sort(a,a+n);


    int l,h;

    l = a[n/2-1];
    h = a[n/2];

    if(l == h){
        std::cout<<0;
    }else{
        std::cout<<h-l;
    }
}