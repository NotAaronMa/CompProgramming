#include <bits/stdc++.h>

void tc(int cs){
    int n; std::cin>>n;
    std::deque<int> o,o1,d,d1;
    bool c1 = true,c2=true;
    for(int i = 0; i < n; i++){
        int a;std::cin>>a;
        o.push_front(a);
        o1.push_front(a);
    }
    d.push_front(o.front());
    o.pop_front();
    while(!o.empty()){
        if(o.front() == d.front()-1){
            d.push_front(o.front());
            o.pop_front();
        }else if(o.front() == d.back() + 1){
            d.push_back(o.front());
            o.pop_front();
        }else if(o.back() == d.front()-1){
            d.push_front(o.back());
            o.pop_back();
        }else if(o.back() == d.back() + 1){
            d.push_back(o.back());
            o.pop_back();
        }else{
            c1=false;
            break;
        }
    
    }
    d1.push_front(o1.back());
    o1.pop_back();
    while(!o1.empty()){
        if(o1.front() == d1.front()-1){
            d1.push_front(o1.front());
            o1.pop_front();
        }else if(o.front() == d.back() + 1){
            d1.push_back(o1.front());
            o1.pop_front();
        }else if(o1.back() == d1.front()-1){
            d1.push_front(o1.back());
            o1.pop_back();
        }else if(o1.back() == d1.back() + 1){
            d1.push_back(o.back());
            o1.pop_back();
        }else{
            c2=false;
            break;
        }
    
    }








     std::cout<<"Case #"<<cs<<": "<<((c1||c2)?"yes\n":"no\n");
    



}
int main(){
    int t;std::cin>>t;
    for(int i = 0; i < t; i++){
        tc(i+1);
    }
    return 0;
}