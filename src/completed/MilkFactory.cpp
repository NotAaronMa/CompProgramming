#include <bits/stdc++.h>



std::set<int> k[101];

int main(){
    int n; std::cin>>n;
    for(int i = 0; i < n-1; i++){
        int a, b; std::cin>>a>>b;
   
        k[b].insert(a);
    }


    std::queue<int>q;

    for(int i =0; i< std::sqrt(n) +1;i++){
        for(int j = 0; j < n; j++){
            for(int a : k[j]){
                for(int b: k[a]){
                    k[j].insert(b);
                }
            }
        }
    }



    for(int i = 1; i <= n; i++){
        /*
        std::cout<<i<<": {";
        for(int x : k[i]){
            std::cout<<x<<",";
        }
        std::cout<<"}\n";
        */
        if(k[i].size() == n-1){
            std::cout<<i;
            return 0;
        }
    }
    std::cout<<-1;

    return 0;
}