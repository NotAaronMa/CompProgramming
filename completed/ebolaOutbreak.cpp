#include <stdio.h>
#include <iostream>
#include <vector>


int* leader;
int* rank;
int find(int s){
    if(leader[s] == s){
        return s;
    }else{
        return find(leader[s]);
    }
}
void merge(int a, int b){
    int la = find(a);
    int lb = find(b);
    if(la != lb){
        leader[la] = lb;
    }
}

int main(){
    int n,m;
    std::cin>>n>>m;
    leader = new int[n+1];
    rank = new int[n+1];
    for(int i = 0; i <= n ; i++){
        leader[i] = i;
        rank[i] = 0;
    }

    for(int i = 0; i < m; i++){
        int k,nl;
        std::cin>>k>>nl;
        for(int i = 1; i < k; i++){
            int o;
            std::cin>>o;
            
            merge(o,nl);
        }
    }
    int f1 = find(1);
    std::vector<int> thing;
    thing.push_back(1);
    for(int i = 2; i <= n; i++){
        if(find(i) == f1){
            thing.push_back(i);
        }
    }
    std::cout<<thing.size()<<"\n";
    for(int i : thing){
        std::cout<<i<<" ";

    }
    return 0;
}
