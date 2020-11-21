#include <bits/stdc++.h>
using ld = long double;
using pld = std::pair<ld,ld>;


ld intersection(pld s1, pld s2){
    ld xi,yi,xj,yj;
    xi= s1.first; yi=s1.second; xj=s2.first; yj=s2.second;
    return (xj*xj+yj*yj-yi*yi-xi*xi)/2*(xj-xi);
    
}

int main(){
    int n;std::cin>>n;
    pld s[n];
    ld left[n],right[n];
    bool out[n];
    for(int i = 0; i < n; i++){
        left[i] = 0;
        right[i] = 1000;
        out[i] = false;
    }

    for(int i = 0; i < n; i++){
        ld xi,yi;std::cin>>xi>>yi;
        s[i] = std::make_pair(xi,yi);
    }



    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            if(i == j){
                continue;
            
            }
            int xi,yi,xj,yj;
            xi= s[i].first; yi=s[i].second; xj=s[j].first; yj=s[j].second;

            if(xi == xj){
                if(yi > yj){
                    out[i] = true;
                    std::cout<<xi<<","<<yi<<" out by y value\n";
                }else{
                    out[j] = true;
                    std::cout<<xj<<","<<yj<<" out by y value\n";
                }
            }else if(!out[j] && !out[i]){
                ld m = intersection(s[i],s[j]);
                if(xi < xj){
                    right[i] = std::min(right[i],m);
                }else{
                    left[i] = std::max(left[i],m);

                }
                  
            }
            
        }
        if(left[i] > right[i]){
            out[i] = true;
            std::cout<<s[i].first<<","<<s[i].second<<" out by segment\n";
        }
        
    }
        
    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    for(int i = 0; i < n; i++){
        if(!out[i]){
            std::cout<<"The sheep at ("<<s[i].first<<","<<s[i].second<<") might be eaten."<<"\n";
        }

    }
    return 0;
    
}