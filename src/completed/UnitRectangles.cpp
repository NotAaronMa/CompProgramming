#include <bits/stdc++.h>
using namespace std;

int N;

void tc(){
    int n;
    std::cin>>n;
    int count = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j<= n; j++){
            if(i*j <= n){
                count++;
            }
        }
    }
    std::cout<<count<<"\n";

}

int main(){
    for(int i = 0; i < 5; i++){
        tc();
    }
}