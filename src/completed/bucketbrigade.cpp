#include <bits/stdc++.h>


int main(){
    int x1,y1,x2,y2,xr,yr;
    

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            char c; std::cin>>c;

            if(c=='B'){
                x1=i;
                y1=j;
            }
            if(c=='L'){
                x2=i;
                y2=j;
            }
            if(c=='R'){
                xr=i;
                yr=j;
            }
        }
    }
    

    int ans = std::abs(x1-x2) + std::abs(y1-y2)-1;

    if((x1 == x2 && x2 == xr && !(yr < std::min(y1,y2) || yr > std::max(y1,y2))) || (y1==y2 && y2 == yr && !(xr < std::min(x1,x2) || xr > std::max(x1,x2)))){
        ans += 2;
    }
    
    std::cout<<ans;


}