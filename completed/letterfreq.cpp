#include <bits/stdc++.h>

int main(){

    std::string s;
    std::getline(std::cin, s);
    int n = s.length();
    int raw[26][n+2];
    int ps[26][n+2];

    for(int i = 0; i< 26; i++){
        for(int j = 0; j < n+2; j++){
            raw[i][j] = 0;
            ps[i][j] = 0;
        }
    }


    for(int i = 0; i < n; i++){
        if(s[i] != ' '){
            raw[s[i]-'a'][i+1] ++;
        }
    }
   

    for(int i = 0; i < 26; i++){
        ps[i][0] = raw[i][0];
        for(int j= 1; j < n+2; j++){
            ps[i][j] = ps[i][j-1] + raw[i][j];
        }
    }

    int q;
    std::cin>>q;
    while(q--){
        int a,b, q;
        char c;
        std::cin>>a>>b>>c;
        q = c-'a';
        std::cout<<ps[q][b] - ps[q][a-1]<<"\n";

    }


    return 0;
}