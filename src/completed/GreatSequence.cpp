#include <bits/stdc++.h>


int seq[100005];
int ps[100005];
std::vector<int> occ[2020];



bool cond2(int a,int b, int l, int r){
    a+=1001;
    b+=1001;
    

    int ra = std::upper_bound(occ[a].begin(), occ[a].end(), r) - occ[a].begin();
    int la = std::lower_bound(occ[a].begin(), occ[a].end(), l)  - occ[a].begin();

    int rb = std::upper_bound(occ[b].begin(), occ[b].end(), r)- occ[b].begin();
    int lb = std::lower_bound(occ[b].begin(), occ[b].end(), l)- occ[b].begin();


    return la<ra && lb<rb;

}
int main(){
    int n,k,q; std::cin>>n>>k>>q;
    

    for(int i  = 1; i <= n; i++){
        std::cin>>seq[i];
        occ[seq[i] + 1001].push_back(i);
    }
    seq[0] = 0;
    ps[0] = seq[0];
    for(int i = 1; i <= n; i++){
        ps[i] = seq[i] + ps[i-1];
    }


    for(int i = 0; i < q; i++){
        int l,r,a,b;

        std::cin>>a>>b>>l>>r;
        if(ps[r] - ps[l-1] > k && cond2(a,b,l,r)){
            std::cout<<"Yes\n";
        }else{
            std::cout<<"No\n";
        }


    }





    return 0;
}