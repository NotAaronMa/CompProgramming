
#include <bits/stdc++.h>

/*
mod 15 we get 
1 2 moo 4 moo moo 7 8 moo moo 11 moo 13 14 moo
8 numbers

*/


int x[9] = {-1,1,2,4,7,8,11,13,14};


int main(){

    int n; std::cin>>n;

    int k = n/8;
    int m = n%8;

    std::cout<<k*15 + x[m];


}