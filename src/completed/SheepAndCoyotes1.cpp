#include <bits/stdc++.h>
using ld = long double;
using pld = std::pair<ld,ld>;


ld intersection(pld s1, pld s2){
    ld a,b,c,d;
    a= s1.first; b=s1.second; c=s2.first; d=s2.second;
    return (c*c+d*d-b*b-a*a)/2*(c-a);
    
}


int main(){
    int n;std::cin>>n;
    pld s[n];
    bool out[n];
    for(int i = 0; i < n; i++){
        out[i] = false;
    }

    for(int i = 0; i < n; i++){
        ld a,b;std::cin>>a>>b;
        s[i] = std::make_pair(a,b);
    }


    for(int i = 0; i < n; i++){
        ld left =0, right = 1000;
        for(int j = 0; j < n; j++){
            int xi,yi,xj,yj;
            xi= s[i].first; yi=s[i].second; xj=s[j].first; yj=s[j].second;
            if(!out[i] && !out[j] && i != j){
                if(xi == xj){
                    if(yi > yj){
                        out[i] = true;
                    }else{
                        out[j] = true;
                    }
                }else{
                    ld c1 = intersection(s[i],s[j]);
                    if(xj<xi){
                        left = std::max(left,c1);
                    }else{
                        right = std::min(right,c1);
                    }
                }
            }
          
        }
        if(right < left){
            out[i] = true;
        }
       
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    for(int i = 0; i < n; i++){
        if(!out[i]){
            std::cout<<"The sheep at ("<<std::round(s[i].first*100)/(ld)100<<","<<std::round(s[i].second*100)/(ld)100<<") might be eaten."<<"\n";
        }

    }
    return 0;
    
}
