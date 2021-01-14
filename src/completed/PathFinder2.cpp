#include<bits/stdc++.h>
const int mm = 500005;
struct inter{
    int s,e,id;
};

bool gt(inter a, inter b){
    return a.s<b.s;
}
std::vector<int>blocks[mm];
std::vector<inter> iv[mm];

int leader[2*mm+1];
int find(int a){
    if(leader[a] == a){
        return a;
    }
    leader[a] = find(leader[a]);
    return leader[a];
}
void merge(int a, int b){
    //std::cout<<"merging "<<a<<" "<<b<<"\n";

    int la = find(a); int lb = find(b);
    leader[la] = lb;
}




int main(){
    int n,m,k,q; std::cin>>n>>m>>k>>q;
    for(int i = 0; i < k; i++){
        int r,c; std::cin>>r>>c;
        blocks[r].push_back(c);
    }
    for(int i = 0; i < 2*mm+1; i++){
        leader[i] = i;

    }
    int id = 1;
    for(int i = 1; i <= n; i++){
        std::sort(blocks[i].begin(), blocks[i].end());
        blocks[i].push_back(m+1);
        int pre = 0;
        for(int j = 0; j < blocks[i].size(); j++){
            if(pre + 1 != blocks[i][j]){
                inter x;
                x.s=pre+1;
                x.e=blocks[i][j]-1;
                x.id=id;
                iv[i].push_back(x); id++;
            }
            pre = blocks[i][j];
        }
    }
    /* 
    for(int i = 1; i<= n;i++){
        for(inter e : iv[i]){
            std::cout<<"("<<e.s<<"->"<<e.e<<","<<"id="<<e.id<<")";
        }
        std::cout<<"\n";
    }
    */
   
   
    for(int i = 1; i < n; i++){
        for(int j = 0; j < iv[i].size(); j++){
            inter x = iv[i][j];
            int l0 = std::lower_bound(iv[i+1].begin(), iv[i+1].end(), x, gt)-iv[i+1].begin();
            l0--;
            int lo = std::max(0, l0);
       
            while(lo < iv[i+1].size() && iv[i+1][lo].s <= iv[i][j].e){
                if(iv[i][j].s <= iv[i+1][lo].e){
                    merge(iv[i+1][lo].id, iv[i][j].id);
                    //std::cout<<"\nmerging row="<<i<<"("<<iv[i][j].s<<"->"<<iv[i][j].e<<") and row="<<i+1<<"("<<iv[i+1][lo].s<<"->"<<iv[i+1][lo].e<<")\n";
                    
                }
                lo++;
            
                if(lo >= iv[i+1].size()){
                    break;
                }
            }
            
        }
    }    

    while(q--){
        int px,py,qx,qy; std::cin>>px>>py>>qx>>qy;
        inter p,q;
        p.s=py,p.e=py;
        q.s=qy,q.e=qy;
        int a,b;


        a = std::lower_bound(iv[px].begin(), iv[px].end(), p,gt)-iv[px].begin()-1;
        b = std::lower_bound(iv[qx].begin(), iv[qx].end(), q,gt)-iv[qx].begin()-1;
        a = std::max(a,0);
        b = std::max(b,0);

        while(! (iv[px][a].s <= py && py <= iv[px][a].e) && a < iv[px].size() ){
            a++;
        }
        while(! (iv[qx][b].s <= qy && qy <= iv[qx][b].e) && b < iv[px].size() ){
            b++;
        }



        //std::cout<<iv[qx][b].s<<" "<<iv[qx][b].e<<" "<<qy<<" \n";
        //std::cout<<iv[px][a].s<<" "<<iv[px][a].e<<" "<<py<<" \n";
        
        if(find(iv[px][a].id) == find(iv[qx][b].id)){
            std::cout<<"YES\n";
        }else{
            std::cout<<"NO\n";
        }
        
    }
    
    return 0;

}