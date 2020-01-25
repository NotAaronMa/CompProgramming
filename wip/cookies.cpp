#include <bits/stdc++.h>
#include <algorithm>

int main(){
    int n;
    std::cin>>n;

    std::pair<int,int> k[n];

    double cx = 0,cy = 0;
    for(int i= 0; i < n; i++){
        int a,b;
        std::cin>>a>>b;
        k[i] = std::make_pair(a,b);
        cx += a;
        cy += b;

    }
    std::pair<int,int>centroid = std::make_pair(cx/(double)n, cy/(double)n);




    double mx = 0;
    

 
                
    for(int i = 0; i < n; i++){
        double dx = k[i].first - centroid.first;
        double dy = k[i].second - centroid.second;
        mx = std::max(sqrt(dx*dx + dy*dy),(double)mx);
        //std::cout<<dx<<" "<<dy<<"\n";
    }
    std::cout<<std::round(mx*200)/(double)100;
    return 0;

}
