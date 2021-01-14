#include <bits/stdc++.h>
const int mm = 5e6+5;
int mpf[mm];

void s(){
    memset(mpf,0,sizeof(mpf));
    for(int i = 2; i < mm; i++){
        
        if(mpf[i] == 0){
            mpf[i] = i;
            for(int j = 1;j*i < mm; j++){
                mpf[j*i] = i;
            }
        }
    }
}

int solve(int k){

    if(k == 1){
        return 0;
    }

    if(mpf[k] == k){
        return k-1 + solve(k-1);
    }else{
        return solve(k/mpf[k]) + solve(mpf[k]);
    }

}



int main(){

    int n; std::cin>>n;
    s();
    std::cout<<solve(n);
    
    //std::cout<<mpf[17];
}