#include <bits/stdc++.h>
int T,G, points[4];

int sp(int* pd,int pr){
    int mx = -__INT_MAX__;
    for(int i : points){
        mx = std::max(mx,i);
    }
    int buckets = std::max(0,mx-points[T]);

    for(int i = 0 ; i< 4; i++){
        if(i != T){
        }
    }
    

}

int main(){
    std::cin>>T>>G;
    T--;

    for(int i=0; i < 4; i++){
        points[i] = 0;
    }
    

    for(int i = 0 ; i < G; i++){
        int t1,t2,p1,p2;
        std::cin>>t1>>t2>>p1>>p2;
        t1--;
        t2--;
        if(p1 == p2){
            points[t1]++;
            points[t2]++;
        }else{
            points[t1] += p1 > p2 ? 3 : 0;
            points[t2] += p1 > p2 ? 0 : 3;
        }
    }

    for(int i = 0; i< 4;i++){
        std::cout<<points[i];
    }

}


