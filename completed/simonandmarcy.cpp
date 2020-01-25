#include <bits/stdc++.h>


int main(){
    int W,N;
    std::cin>>N>>W;

    int wt[N+1], val[N+1];
    int dp[W+2][N+1];


    for(int i = 0; i <= W+1;i++){
        for(int j = 0; j < N+1;j ++){
            dp[i][j] = 0;
        }
    }


    for(int i = 1; i <= N  ;i++){
        int a,b;
        std::cin>>val[i]>>wt[i];
    }
    
    for(int n = 1; n <= N; n++){
    //weight #
        for(int w = 1; w <= W+1; w++){
        //item #
            //dont take i 
            int alt =  std::max(dp[w-1][n], dp[w][n-1]);
            //can fit i in weight j
            if(wt[n] <= w){
                
                alt = std::max(alt, dp[w-wt[n]][n-1] + val[n]);
            }
            dp[w][n] = std::max(dp[w][n], alt);
        
        }
    }
    std::cout<<dp[W][N];

    
    


    return 0;
}