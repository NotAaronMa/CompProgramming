#include <bits/stdc++.h>
const int mx = 1000000;
using pii = std::pair<int,int>;

int max[mx];
int main(){
    int N,I,H,M;
    std::cin>>N>>I>>H>>M;
    for(int i = 0; i <= N; i++){
        max[i] = H;
    }

    pii thing[M];
    for(int i = 0; i < M; i++){
        int a,b;
        std::cin>>a>>b;
        thing[i] = std::make_pair(b,a);

    }
    std::sort(thing, thing + M);
 
    for(int i = 0 ; i < M; i++){
        int b = thing[i].first;
        int a = thing[i].second;
        max[a] = std::min(max[a],max[b]);
        if(b > a){
            for(int i = a +1; i < b; i++){
                max[i] = std::min(max[i],max[a]-1);
            }
        }else{
            for(int i = b+1; i < a; i++){
                max[i] = std::min(max[i],max[a]-1);
            }
        }
    }
    
   

    for(int i = 1; i <= N; i++){
        std::cout<<max[i]<<"\n";
    }
    return 0;
}