#include <bits/stdc++.h>


int main(){
    int n; std::cin>>n;


    char k[n+2][n+2];

    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < n+2; j++){
            k[i][j] = '.';
        }
    }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            std::cin>>k[i][j];
        }
    }


    char win = '.';


    for(int i = 1; i <=n; i++){
        for(int j = 1; j <=n; j++){
            if(k[i][j]!='.'){
                if(k[i-1][j-1] == k[i][j] && k[i+1][j+1] == k[i][j]){
                    win = k[i][j];
                }
                 if(k[i-1][j+1] == k[i][j] && k[i+1][j-1] == k[i][j]){
                    win = k[i][j];
                }
                if(k[i-1][j] == k[i][j] && k[i+1][j] == k[i][j]){
                    win = k[i][j];
                }
                if(k[i][j-1] == k[i][j] && k[i][j+1] == k[i][j]){
                    win = k[i][j];
                }
            }   
        }
    }

    if(win == '.'){
        std::cout<<"ongoing";
    }else{
        std::cout<<win;
    }





    return 0;
}