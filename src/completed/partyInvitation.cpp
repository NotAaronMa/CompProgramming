#include <bits/stdc++.h>

int main(){

    int n,m; std::cin>>n>>m;
    int arr[n+1][2];
    for(int i = 0; i < n; i++){
        arr[i][1] = i+1;
    }
    int l = n;
    for(int i = 0; i < m; i++){
        int v; std::cin>>v;
        for(int j = 0; j < n; j++){
            arr[j][0] = arr[j][1];
            arr[j][1] = 0;
        }
        int c = 0;
        for(int j = 0;  j < l;j++){
            if((j+1) % v != 0){
                arr[c][1] = arr[j][0];
                c++;
            }
        }
        l = c;



    }

    

    for(int i = 0; i < l; i++){
        std::cout<<arr[i][1]<<"\n";
    }


}