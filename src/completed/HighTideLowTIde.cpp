#include <bits/stdc++.h>


int main(){
    int n; std::cin>>n;
    int k[n];
    for(int i = 0; i < n; i++){
        std::cin>>k[i];
    }
    std::sort(k,k+n);
    std::vector<int>low,high;
   
    for(int i = 0; i < n/2;i++){
        if(n-1-i > i){
            low.push_back(k[i]);
            high.push_back(k[n-1-i]);    
        }
    }

    if(n%2 == 0){
        for(int i = 0; i < n/2;i++ ){
            std::cout<<low[low.size()-1-i]<<" "<<high[high.size()-1-i]<<" ";
        }
    }else{
        std::cout<<k[n/2]<<" ";
         for(int i = 0; i < n/2;i++ ){
            std::cout<<high[high.size()-1-i]<<" "<<low[low.size()-1-i]<<" ";
        }
    }
}