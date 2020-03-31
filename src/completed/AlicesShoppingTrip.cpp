#include <bits/stdc++.h>
int main(){
    int t,n;
    std::cin>>t>>n;

    std::priority_queue <int> neg, pos;

    for(int i = 0; i < n; i++){
        int nex;
        std::cin>>nex;
        if(nex < 0){
            neg.push(nex);
        }else{
            pos.push(-nex);
        }
    }
    int tt,p;
    tt = p = 0;
    while(t > 0){
        if(neg.top() > pos.top() && !neg.empty()){
            int dest = neg.top();
            neg.pop();

            int travel = std::abs(p - dest);
            if(travel > t){
                std::cout<<tt;
                return 0;
            }else{
                p = dest;
                t-=travel;
                tt++;
            }
        }else if(!pos.empty()){
            int x = -pos.top();
            pos.pop();
            int travel = std::abs(p-x);
            if(travel > t){
                std::cout<<tt;
                return 0;
            }else{
                p = x;
                t -= travel;
                tt++;
            }

        }
        if(pos.empty() && neg.empty()) break;

    }
    std::cout<<tt;

    return 0;
}