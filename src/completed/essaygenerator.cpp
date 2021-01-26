#include <bits/stdc++.h>
using str = std::string;
std::vector<str> w1,w2,w3;



int main(){
    int n;
    std::cin>>n;
    for(int i = 0; i < 26; i++){
        str x;
        x.push_back((char)(i+'a'));

        w1.push_back(x);
        for(int j = 0; j < 26; j++){
            x.push_back((char)(j+'a'));
            w2.push_back(x);
            for(int k = 0; k < 26; k++){
                x.push_back((char)(k+'a'));
                w3.push_back(x);    
                x.pop_back();
            }
            x.pop_back();
        }
        x.clear();

    }



    
    for(int i = 0; i < w1.size(); i++){
        std::cout<<w1[i]<<" ";
        n--;
        if(n == 0){
            return 0;
        }
    }
    for(int i = 0; i< w2.size(); i++){
        std::cout<<w2[i]<<" ";
        n--;
        if(n == 0){
            return 0;
        }
    }

    for(int i = 0; i< w3.size(); i++){
        std::cout<<w3[i]<<" ";
        n--;
        if(n == 0){
            return 0;
        }
    }
    

    return 0;
}