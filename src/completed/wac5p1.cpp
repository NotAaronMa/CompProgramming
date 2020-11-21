#include <bits/stdc++.h>

int main(){
    int n; std::cin>>n;


    std::vector<int> thing;
    for(int i = 0; i < n; i++){
        int k; std::cin>>k;
        thing.push_back(k);
    }
    std::sort(thing.begin(), thing.end());
    int t = 0;
    while(!thing.empty()){
        if(thing[thing.size() -1] == 0){
            thing.pop_back();
            continue;
        }
        int cur = thing[thing.size() - 1];

        /*
        std::cout<<cur<<"\n";
        for(int i = 0; i < thing.size();i++){
            std::cout<<thing[i]<<" ";
        }
        std::cout<<"\n";
        */
        thing.pop_back();
        t += cur;

        for(int i = thing.size() - 1; i >= 0; i--){
            if(thing[i] < cur && thing[i] != 0){
                cur = thing[i];
                thing[i] = 0;
            }
        }
        

    }
    std::cout<<t<<"\n";



    return 0;
}