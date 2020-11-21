#include <bits/stdc++.h>
using str = std::string;


int main(){

    std::stack<double> stk;
    
    str s;
    std::getline(std::cin,s);


    std::vector<str> k;
    int p = 0;
    for(int i = 0; i < s.size();i++){
        if(s[i] == ' '){
            k.push_back(s.substr(p,i-p));
            p = i+1;
        }
    }
    k.push_back(s.substr(p,s.size()-p));

    for(int i= 0; i < k.size();i++){
        //std::cout<<"a"<<k[i]<<"a"<<"\n";
        if(k[i][0] == '+'){
            double a,b;
            a = stk.top(); stk.pop();
            b = stk.top(); stk.pop();
            stk.push(a+b);

        }else if(k[i][0] == '-'){
            double a,b;
            a = stk.top(); stk.pop();
            b = stk.top(); stk.pop();
            stk.push(b-a);
            
        }else if(k[i][0] == '*'){
            double a,b;
            a = stk.top(); stk.pop();
            b = stk.top(); stk.pop();
            stk.push(a*b);
        }else if(k[i][0] == '/'){
            double a,b;
            a = stk.top(); stk.pop();
            b = stk.top(); stk.pop();
            stk.push(b/a);
        }else if(k[i][0] == '^'){
            double a,b;
            a = stk.top(); stk.pop();
            b = stk.top(); stk.pop();
            stk.push(std::pow(b,a));
        }else if(k[i][0] == '%'){
            double a,b;
            a = stk.top(); stk.pop();
            b = stk.top(); stk.pop();
            stk.push((int)b%(int)a);
        }else{
            double a = std::stod(k[i]);
            stk.push(a);
        }
        
    }

    std::cout<<stk.top();
    

    return 0;
}