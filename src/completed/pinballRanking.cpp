#include <bits/stdc++.h>


const int mm = 200005;
long long bit[mm];
long long re[mm];
long long r2[mm];
std::map<int,int> rtv;



long long qry(int id){
    long long s = 0;
    while(id >0){
        s += bit[id];
        id -= (id & -id);
    }
    return s;
}

void upd(int id, int n){
    while(id < mm){
        bit[id]+=n;
        id += (id & -id);
    }
}




int main(){
    memset(bit,0,sizeof(bit));
    memset(re,0,sizeof(re));
    memset(r2,0,sizeof(r2));
    int n; std::cin>>n;
    for(int i = 0; i < n; i++){
        std::cin>>re[i];
        re[i]++;
        r2[i] = re[i];
    }
    std::sort(r2,r2+n);
    int vs = 1;
    rtv[r2[0]] = vs;
    for(int i = 1; i < n; i++){
        if(r2[i] > r2[i-1]){
            vs++;
        }
        rtv[r2[i]] = vs;
    }

    for(int i = 0; i < n; i++){
        re[i] = rtv[re[i]];
    }

    int ins = 1;

    long double total = 0;
    for(int i = 0; i < n;i++){

        int up = ins - qry(re[i]);
        upd(re[i],1);
        ins++;    

        total += up;
    }
    
    std::cout<<std::fixed;
    std::cout<<std::setprecision(2);
    
    std::cout<<rint(100*total/(long double)n)/(long double)100;



       
}

