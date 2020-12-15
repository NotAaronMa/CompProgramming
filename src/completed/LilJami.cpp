#include <bits/stdc++.h>

const int mm = 1000001;

int ps[mm], qr[mm];
int main(){
    memset(ps,0,sizeof(ps));
    memset(qr,0,sizeof(qr));
    int n,k; std::cin>>n>>k;

    for(int i = 0; i < k; i++){
        int a; std::cin>>a; 
        ps[a]++;
    }
    qr[0] = ps[0];
    for(int i =1;i<= n;i++){
        qr[i] = qr[i-1] + ps[i];
    }
    int q; std::cin>>q;

    for(int i = 0; i < q; i++){

        int a,b;std::cin>>a>>b;

        std::cout<<qr[b]-qr[a-1]<<"\n";
    }



    return 0;
}