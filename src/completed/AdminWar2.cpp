#include <bits/stdc++.h>
const int mm = 100000;
int a[mm], b[mm], n;
int solve(){
    int iol = 0;
    int wins = 0;
    for(int i = 0; i < n;){
        if(a[i]> b[iol]){       
            i++;
            iol++;
            wins++;
        }else{
            i++;
        }
    }
    return wins;
}

int main(){
    std::cin>>n;
    for(int i = 0; i < n; i++){
        std::cin>>a[i];
    }

    for(int i = 0; i < n; i++){
        std::cin>>b[i];
    }



    std::sort(b,b+n);
    std::sort(a,a+n);


    std::cout<<solve()<<"\n";
    std::swap(a,b);
    std::cout<<solve()<<"\n";






    return 0;

}