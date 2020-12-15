#include <bits/stdc++.h>

int main(){
    int n; std::cin>>n;
    int g[n+1],first[n+1],b[n+1];
    std::cin>>g[1];
    bool same = true;


    for(int i = 0; i <= n; i++){
        first[i] = -1;
        b[i] = -1;
    }
    for(int i = 2; i <= n; i++){
        std::cin>>g[i];
        if(g[i]!=g[1]){
            same=false;
        }
    }
    if(same){
        std::cout<<-1;
        return 0;
    }
    std::set<int>gaurded;
    std::queue<int>vacant;
    for(int i = 1; i<= n;i++){
        if(first[g[i]] == -1){
            first[g[i]] = i;
            gaurded.insert(g[i]);
        }
    }
    std::vector<int> v(gaurded.size());
    std::copy(gaurded.begin(),gaurded.end(),v.begin());
    for(int i = 1; i < v.size(); i++){
        b[first[v[i]]] = v[i-1]; 
    }
    b[first[v[0]]] = v[v.size()-1];

    for(int i = 1; i <= n ;i++){
        if(first[i] == -1){
            vacant.push(i);
        }
    }
    for(int i = 1; i <= n; i++){
        if(b[i] == -1){
            b[i] = vacant.front(); vacant.pop();
        }
    }


    std::cout.tie(0);
    
    for(int i = 1; i <=n;i++){
        std::cout<<b[i]<<" ";
    }
    return 0;
}