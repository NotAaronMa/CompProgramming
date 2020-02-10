#include <stdio.h>
#include <iostream>

int main(){
    int a,b,n;
    std::cin>>n;
    while(n--){
        std::cin>>a>>b;
        std::cout<<a+b<<"\n";
    }
    return 0;
}