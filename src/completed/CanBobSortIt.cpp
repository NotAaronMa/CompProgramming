#include <bits/stdc++.h>
const int mm = 100000;
int a[2][mm];
int main(){

    int n;
    std::cin>>n;

    for(int i = 0; i < n; i++){
        std::cin>>a[0][i];
        a[1][i] = a[0][i];
    }

    std::sort(a[1],a[1]+n);

    int diff = 0;

    for(int i = 0; i < n; i++){
        if(a[1][i] != a[0][i]){
            diff++;
        }    
    }

    if(diff <= 2){
        std::cout<<"YES";
    }else{
        std::cout<<"NO";
    }
}