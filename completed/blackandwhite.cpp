#include <bits/stdc++.h>

signed short diff[10001][10001];
int main(){
    int n,m;
    std::cin>>n>>m;
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < n+1; j++){
            diff[i][j] = 0;
        }
    }

    //maintain a 2d diff array

    while(m--){
        int x,y,x1,y1,l,w;
        std::cin>>x>>y>>l>>w;
        x1 = x+l;
        y1 = y+w;

        diff[x][y] = (diff[x][y] +1) % 2;
        diff[x1][y1] = (diff[x1][y1] +1)  % 2;
        diff[x1 ][y] = (diff[x1][y] - 1) % 2;
        diff[x][y1] = (diff[x][y1] - 1) % 2;
       

       
    }

    for(int i = 1; i < n; i++){
        diff[0][i] +=diff[0][i-1]; 
        diff[i][0] +=diff[i-1][0];
    }
    long long t = 0;

    for(int i = 1; i < n; i++){
       
        for(int j = 1; j < n; j++){
            
            diff[i][j] += (diff[i-1][j] + diff[i][j-1] -diff[i-1][j-1]);
        }

    }

    for(int i = 0; i < n; i++){
        //std::cout<<"\n\n";
        for(int j = 0; j < n; j++){
           // std::cout<<(int)diff[i][j]<<" ";
            t+= abs((diff[i][j]) % 2);
        }
    }
    std::cout<<t;
   


    return 0;
}


