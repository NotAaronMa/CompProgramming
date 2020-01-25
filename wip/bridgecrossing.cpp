#include <bits/stdc++.h>

int M,Q;




int main(){
    std::cin>>M>>Q;
    
    //stores max from person i -> j
    int RMQ[Q+1][Q+1],time[Q+1];

    for(int i = 0; i <= M;i++ ){
        for(int j =0; j <= M; j++){
            RMQ[i][j] = -__INT_MAX__;
        }
        if(i != 0) std::cin>>time[i];
    }

    

    for(int i = 1; i < M+1; i++){
        for(int j = 1; i < M+1;j++){
        
        }

    }
    

    


}


