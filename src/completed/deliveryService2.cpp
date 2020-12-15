#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int mm = 100005;
int x[mm];

/*

da goes this way ->

db goes this way <-

*/




int main(){
    int n,d;cin>>n>>d;
    for(int i = 1; i <= n; i++){
        cin>>x[i];
    }
    int pmax = -__INT_MAX__,pmin = __INT_MAX__,dmax = -__INT_MAX__,dmin=__INT_MAX__;
    int a1 = 0,b1 = 0;
    for(int i = 0; i < d; i++){
        int a,b;
        cin>>a>>b;


        if(x[a] < x[b]){
            a1++;
        }else{
            b1++;
        }

        pmax = max(x[a],pmax);
        pmin = min(x[a],pmin);


        dmax = max(x[b],dmax);
        dmin = min(x[b],dmin);
    }
    if(a1 == 0 || b1 == 0){
        cout<<max(pmax,dmax) - min(pmin,dmin);
        return 0 ;
    }    
    int a,b;
    a = max(pmax,dmax)-pmin + abs(max(pmax,dmax)-dmin);
    b = pmax-min(pmin,dmin) + abs(min(pmin,dmin)-dmax);
    cout<<min(a,b);
    

}