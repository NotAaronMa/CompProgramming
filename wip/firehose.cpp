#include <bits/stdc++.h>

int main(){
    int H,K, h[1000];
    std::cin>>H;
    for(int i = 0; i < H; i++){
        std::cin>>h[i];
    }
    std::cin>>K;
    if(K >= H){
        std::cout<<0;
        return 0;

    }
    std::sort(h,h+H);

    for(int l = 0; l < 1000000; l++){
        //check if thing works for length[i];
        int hr =0;
        if(1000000 + h[0] - h[H-1] <= l){
        }
        for(int i = 0; i < H; i++){
            

        }

        
    }





    return 0;
}