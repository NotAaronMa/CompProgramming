#include <bits/stdc++.h>


int main(){
    int n; std::cin>>n;
    long double a[n];

    for(int i = 0; i < n; i++){
        std::cin>>a[i];
    }
    std::sort(a,a+n);

    long double mm = __INT_MAX__;
    for(int i = 1; i < n-1; i++){
        long double m = (a[i+1] - a[i-1])/(long double)2;
        mm = std::min(m,mm);

    }
    std::cout<<std::fixed;
    std::cout<<std::setprecision(1);
    std::cout<<mm;


    return 0;
}