#include <bits/stdc++.h>

int main(){
    int a,b,c;

    std::cin>>a>>b>>c;


    bool s1 = a + b > c;
    bool s2 = a + c > b;
    bool s3 = b + c > a;
    std::cout<<((s1 && s2 && s3) ? "yes" : "no")<<"\n";


    return 0;
}