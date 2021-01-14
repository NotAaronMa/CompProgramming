#include <bits/stdc++.h>

int main(){
    int a,b;std::cin>>a>>b;
    long long ans = 1;

    for(int i = 0; i < a; i++){
        ans*=b;
    }
    std::cout<<ans;

    return 0;

}