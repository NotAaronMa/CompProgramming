#include <bits/stdc++.h>
const int mm = 2e5+5;

int prime[mm];

void s(){
    prime[1] = false;
    prime[2] = true;
    
    for(int i = 2; i < mm; i++){
        if(prime[i]){
            for(int j = 2; j*i < mm; j++){
                prime[j*i] = false;
            }
        }
    }
}



int main(){
    int n; std::cin>>n;
    std::fill(prime,prime+mm,true);
    s();
    int ans=0;

    for(int i =0; i < n; i++){
        int a; std::cin>>a;
        if(prime[a]){
            ans++;
        }

    }

    std::cout<<ans;
    return 0;

    
}