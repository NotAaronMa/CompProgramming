#include <bits/stdc++.h>


int ps [505], ba[505];



int main(){
    int n;std::cin>>n;
    memset(ps,0,sizeof(ps));
    memset(ba,0,sizeof(ba));


    ba[2]++;
    for(int i = 3; i < 505; i++){
        bool prime = true;
        for(int j = 2; j < std::sqrt(i)+1; j++){
            if(i%j == 0){
                prime = false;
            }
        }
        if(prime){
            ba[i]++;
        }
    }

    ps[0] = ba[0];
    for(int i = 1; i < 505; i++){
        ps[i] = ps[i-1]+ba[i];
        
    }

    for(int i = 0; i < n; i++){


        int a,b;
        std::cin>>a>>b;

        std::cout<<ps[b-1]-ps[a-1]<<"\n";
    }
    return 0;
}