#include <bits/stdc++.h>


int main(){
    int n;std::cin>>n;
    int k[n]; 
    std::set<int> a; 

    for(int i = 0; i < n; i++){
        std::cin>>k[i];
        a.insert(k[i]);
    }
    std::sort(k,k+n);
    int mm = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int d = k[j]-k[i];
            if((a.find(k[j] + d) != a.end()) && d > 0){
                mm = std::max(mm,3*k[i] + 3*d);
            }
        }
    }
    std::cout<<mm;



    return 0;
}