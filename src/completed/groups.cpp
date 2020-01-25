#include <bits/stdc++.h>


int n;
bool tc(){
    n++;
    int group[n+1][n];
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            std::cin>>group[i][j];
        }
    }
    
    //find identity
    int id = -1;
    for(int i= 1; i < n; i++){
        bool flag =true;
        for(int j = 1;j < n; j++){
            flag &= group[i][j] == j && group[j][i] == j;
        }
        if(flag){
            id = i;
        }
    }
    if(id == -1){
        return false;
    }
    //check for inverse
    //std::cout<<id;

    for(int i = 1; i < n; i++){
        bool flag = false;
        for(int j = 1; j < n; j++){
            flag = flag || group[i][j] == id;
        }
        if(!flag){
            return false;
        }
    }
    for(int i= 1; i < n;i ++){
        bool rhas[n+1], jhas[n + 1];
        for(int j = 0; j < n;j++){
            rhas[j] = false;
            jhas[j] = false;
        }

        for(int j = 1; j < n;j++){
            if(rhas[group[i][j]]){
                return false;
            }else{
                rhas[group[i][j]] = true;
            }
            if(jhas[group[j][i]]){
                return false;
            }else{
                jhas[group[j][i]] = true;
            }
        }
    }

    
    
    return true;



}

int main(){


    while(true){
        std::cin>>n;
        if(n == 0){
            return 0;
        }
        std::cout<< (tc() ? "yes": "no")<<"\n" ;
    }
    return 0;
}