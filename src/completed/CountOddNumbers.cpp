#include <bits/stdc++.h>





int main(){
    unsigned long long b; std::cin>>b;


    std::string s = std::to_string(b);    

    unsigned long long ans = 0;
    
    if(s.length() %2==1){
        ans+= b-std::pow(10,s.length()-1)+1;
    }
    unsigned long long a = 10;
    for(int i = 1; i < s.length(); i+=2){
        ans+= a-(a/10);
        //std::cout<<ans<<"\n";
        a*=100;
    }


    
    std::cout<<ans;


    return 0;
}