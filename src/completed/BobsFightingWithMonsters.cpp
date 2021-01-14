#include <bits/stdc++.h>

int main(){
    long long n,k;std::cin>>n>>k;

    std::cout<<  std::min(((-n)%k + k)%k,n%k);


}