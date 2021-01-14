#include <bits/stdc++.h>

typedef long long ll;
const int mm = 2e5+5;
int n,m,q,a[mm];
struct node{
    int l,r;
    ll sum,lz;
};

node seg[3*mm];


void pushup(int idx){
    int lc = 2*idx;
    int rc = 2*idx+1;
    seg[idx].sum = (seg[lc].sum + seg[rc].sum) % m;
}


void pushdn(int idx){
    int lc = 2*idx;
    int rc = 2*idx+1;

    seg[lc].lz += seg[idx].lz;
    seg[rc].lz += seg[idx].lz;

    seg[lc].sum += (ll)(seg[lc].r - seg[lc].l + 1) *seg[idx].lz;
    seg[rc].sum += (ll)(seg[rc].r - seg[rc].l + 1) *seg[idx].lz;
    seg[idx].lz = 0;
}

void build(int l, int r, int idx){
    seg[idx].l = l; seg[idx].r = r;
    if(l == r){
        seg[idx].sum = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(l,mid,2*idx); build(mid+1,r,2*idx+1); pushup(idx);
}


void upd(int l, int r, int val, int idx){
    int lc = 2*idx;
    int rc = 2*idx+1;
    //std::cout<<"updating segment :"<<l<<"->"<<r<<"idx = "<<idx<<"\n";
    if(seg[idx].l == l && seg[idx].r == r){
        seg[idx].sum += (ll)val*(r-l+1);
        seg[idx].lz += val;
        return;
    }
    int mid = (seg[idx].l+seg[idx].r)/2;  
    if(seg[idx].lz != 0){
        pushdn(idx);
    }
    if(l > mid){
        upd(l,r,val,rc);
    }else if(r <= mid){
        upd(l,r,val,lc);
    }else{
        upd(l,mid,val,lc);
        upd(mid+1,r,val,rc);
    }
    pushup(idx);
    return;
}

ll qry(int l, int r, int idx){
    int lc = 2*idx;
    int rc = 2*idx+1;
    //std::cout<<"querying segment: "<<l<<"->"<<r<<" idx ="<<idx<<"\n";

    if(seg[idx].l == l && seg[idx].r == r){
        return seg[idx].sum;
    }

    if(seg[idx].lz != 0){
        pushdn(idx);
    }
    int mid = (seg[idx].l+seg[idx].r)/2;


    if(r <= mid) return qry(l, r, lc);
    if(l > mid) return qry(l, r, rc);
    return qry(l, mid, lc) + qry(mid+1, r, rc);
}


int main(){
    std::cin>>m>>n>>q;
    for(int i = 1; i <=n; i++){
        std::cin>>a[i];
    }
    build(1,n,1);

    for(int i = 1; i <=q; i++){
        int op,l,r; std::cin>>op>>l>>r;
        if(op == 1){
            int x; std::cin>>x;
            upd(l,r,x,1);
        }else{
            std::cout<<qry(l,r,1)%m<<"\n";
        }
    }
}

