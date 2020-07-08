#include <bits/stdc++.h>
using ll = long long;
int t[405][405], left[406][406];

int main(){
    int r,c;std::cin>>r>>c;
    for(int i = 0; i < 405; i++){
        memset(t[i],0,sizeof(t[i]));
        memset(left[i],0,sizeof(left[i]));
    }
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            char c; std::cin>>c;
            t[i][j] = (c == 'X');
        }
    }
    for(int i = 1; i <= r; i++){
        left[i][0] = t[i][0];
        for(int j = 1; j <= c+2; j++){
            left[i][j] = t[i][j] + left[i][j-1];
        }
    }
/*
    for(int i = 1; i <= r; i++){
        for(int j = 0; j <= c; j++){
            std::cout<<left[i][j]<<" ";
        }
        std::cout<<"\n";
    }
*/


    int mp =0;

    for(int lt = 1; lt<= c; lt++){
        for(int rt = lt; rt<= c; rt++){
            
            
            int cp = 2*(rt - lt +1);

            for(int u = 1; u <= r; u++ ){
                if(left[u][rt] - left[u][lt-1] == 0){
                    cp += 2;
                }else{
                    if(cp != 2*(rt - lt +1)) mp = std::max(cp,mp);
                    cp = 2*(rt-lt+1);
                }
            }
            if(cp != 2*(rt - lt +1)) mp = std::max(cp,mp);
            //std::cout<<lt<<" "<<rt<<" "<<mp<<"\n";
        }
    }
    std::cout<<mp-1<<"\n";
    

    return 0;
}