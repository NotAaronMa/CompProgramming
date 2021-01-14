#include <bits/stdc++.h>
using str = std::string;



const int mm = 100005;

int pre[mm][26], suf[mm][26];

int main(){
    int n; str x; std::cin>>n>>x;
    for(int i = 0; i < mm; i++){
        memset(pre[i],0,sizeof(pre[i]));
        memset(suf[i],0,sizeof(suf[i]));
    }


    pre[0][x[0]-'a'] ++;
    suf[n-1][x[n-1]-'a']++;

    for(int i = 1; i < n-1; i++){
        pre[i][x[i]-'a']++;
        
        suf[n-1-i][x[n-1-i] - 'a']++;



        for(int j = 0; j < 26; j++){
            pre[i][j] += pre[i-1][j];
            suf[n-1-i][j] += suf[n-i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < n-1; i++){
        int score = 0;
        for(int j = 0; j < 26; j++){
            if(pre[i][j] > 0 && suf[i+1][j] > 0){
                score++;
            }
        }
        //std::cout<<i<<" "<<score<<"\n";

        ans = std::max(ans,score);
    }
    std::cout<<ans;




    return  0;
}