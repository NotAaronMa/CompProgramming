#include <bits/stdc++.h>

using tii = std::tuple<int,int,int>;
const int mm = 500002;
int bit[mm],r[3][mm];
tii res[mm];



int qry(int id){
    int ret = __INT_MAX__;

    while(id > 0){

        ret = std::min(ret,bit[id]);
        id -= (id & -id);

    }
    return ret;

}

void upd(int id, int val){
    while(id < mm){
        bit[id] = std::min(bit[id],val);
        id += (id & -id);
    }
}


int main(){
    for(int i= 0; i < mm; i++){
        bit[i] = __INT_MAX__;
    }

    int n; std::cin>>n;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            int id; std::cin>>id;
            r[i][id] = j+1;
        }
    }

    for(int i = 1; i <= n; i++){
        int a,b,c;
        a = r[0][i];
        b = r[1][i];
        c = r[2][i];
        res[i-1] = std::make_tuple(a,b,c);

    }
    std::sort(res, res+n);

    int e = 0;


    for(int i = 0; i < n; i++){
        
        int b,c;
        b = std::get<1>(res[i]); c = std::get<2>(res[i]);

        //std::cout<<"("<<std::get<0>(res[i])<<","<<b<<","<<c<<")\n";
        if(qry(b) > c){
            e++;
        }


        upd(b,c);
    }
    std::cout<<e;
}