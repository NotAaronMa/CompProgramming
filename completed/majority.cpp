#include <bits/stdc++.h>

long long bit[150000], psa[150000];
long long N;

void upd(long long ind, long long val){
    for(long long i =ind; i<= N; i += (i & (-i))){
        bit[i] += val;
    }
}

long long qry(long long x){
    long long sum = 0;
    while(x > 0){
        sum += bit[x];
        x -= (x & (-x));
    }
    return sum;
}
int main(){
    std::cin>>N;
    psa[0] = 0;
    bit[0] = 0;
    long long mn = __LONG_LONG_MAX__;
    for(int i = 1; i <= N; i++){
        bit[i] = 0;
        int a;
        std::cin>>a;
        psa[i] = psa[i-1] + (a == 2 ? -1:1);
        mn = std::min(psa[i],mn);
    }

    for(int i = 0; i < N+1; i++){    
        psa[i] -=mn-1;  
       // std::cout<<psa[i]<<" ";      
    }
    
    long long ways =0;
    upd(psa[0],1);
    for(int i = 1; i <= N; i++){
        //std::cout<<"qry: "<<psa[i]<<" \n";
        ways +=qry(psa[i]-1);
        upd(psa[i],1);
    }    
    std::cout<<ways;
    return 0;
}