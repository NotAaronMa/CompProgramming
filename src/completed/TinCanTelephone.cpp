#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double,double> pii;

pii add(pii a, pii b){
    return make_pair(a.first + b.first, a.second + b.second);
}
pii neg(pii a){
    return make_pair(-a.first, -a.second);
}
pii sub(pii a, pii b){
    return add(a, neg(b));
}

double dot(pii a, pii b){
    return a.first*b.first + a.second*b.second;
}
double mag(pii a){
    return sqrt(pow(a.first,2) + pow(a.second,2));
}
pii unit(pii a){
    double mg = mag(a);
    return make_pair(a.first/mg,a.second/mg);
}

bool equals(pii a,pii b){
    double threshold = 10e-9;
    return abs(a.first -b.first) < threshold && abs(a.second - b.second) < threshold;
}
double gs(double d){
    return d < 0 ? -1 : 1;
}

bool between(pii s, pii e, pii c){
    bool a = s.first <= c.first && s.second <= c.second;
    bool b = c.first <= e.first && c.second <=e.second;
    bool na = s.first >= c.first && s.second >= c.second;
    bool nb = c.first >= e.first && c.second >= e.second;
    return (a && b) || (na && nb);
}

bool inter(pii s, pii e, pii s1, pii e1 ){
    pii d1 = sub(e1,s1);
    pii d = sub(e,s);
    
    //paralel case
    pii n = unit(d),n1 = unit(d1);
    if(equals(n,n1) || equals(n,neg(n1))){
        //std::cout<<"p";
        pii vec = sub(s1,s);
        bool colin = abs(vec.first/vec.second - d.first/d.second) < 10e-9;
        if(colin){
            return between(s,e,s1) || between(s,e,e1) || between(s1,e1,s) || between(s1,e1,e);
        }
        return false;
    }
    if(d.first == 0){
        //s1[x]  + u*d1[x] = s.first
        double u  = (s.first - s1.first)/d1.first;
        pii is = make_pair(s1.first + u*d1.first, s1.second + u*d1.second);
        return (between(s,e,is) && between(s1,e1,is));
    }else if(d.second == 0){
        double u  = (s.second - s1.second)/d1.second;
        pii is = make_pair(s1.first + u*d1.first, s1.second + u*d1.second);
        return (between(s,e,is) && between(s1,e1,is));
    }else{
        double xl = (s.first - s1.first)*d.second;
        double yl = (s.second - s1.second)*d.first;
        double u = (xl-yl)/(d1.first*d.second - d1.second*d.first); 
        double t = -1*(s.first - s1.first - u*d1.first)/(d.first == 0 ? d.second:d.first);
        pii is = make_pair(s.first + t*d.first, s.second + t*d.second);
        return (between(s,e,is) && between(s1,e1,is));
       
    }
   

}




int main(){
    pii start,end;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    start = make_pair((double)a,(double)b);
    end = make_pair((double)c,(double)d);

    int n; cin>>n;
    int ans = 0;

    for(int i= 0; i < n; i++){
        int v;
        cin>>v;
        pii vert[v];
        for(int i=0; i < v; i++){
            std::cin>>a>>b;
            vert[i] = make_pair((double)a,(double)b);
        }
        bool colides = false;
        for(int i = 1; i < v; i++){
            colides = colides || inter(start,end,vert[i], vert[i-1]);
            //std::cout<<i;
        } 
        colides = colides || inter(start,end,vert[0],vert[v-1]);
        ans += colides; 
    }
    std::cout<<ans;

    
    return 0;
}