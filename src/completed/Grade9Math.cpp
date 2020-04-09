#include <bits/stdc++.h>

long double inf = __INT_MAX__;

long double thresh = 10e-7;


int main(){
    long double x1,x2,y1,y2,x11,x22,y11,y22;
    std::cin>>x1>>y1>>x2>>y2>>x11>>y11>>x22>>y22;


    if(abs(x1 - x2) < thresh){
        std::swap(x1, x11);
        std::swap(y1, y11);
        std::swap(x2, x22);
        std::swap(y2, y22);
    }
    if(abs(x11 -x22) < thresh){
        if(abs(x1-x2) < thresh){
            std::cout<<(abs(x1 - x11) > thresh ? "parallel": "coincident")<<"\n";
        }else{
            long double m1 = (y1-y2)/(x1-x2);
            long double b1 = (y1 - m1*x1);
            long double y = std::round((m1 * x11 + b1)*10e6)/10e6; 
            long double x = std::round(x11*10e6)/10e6;
            
            std::cout<<std::fixed<<std::setprecision(6)<<x<<" "<<y<<"\n";

        }
        return 0;

    }

    long double m1 = (y1-y2)/(x1-x2);
    long double m2 = (y11-y22)/(x11-x22);
    long double b1 = (y1 - m1*x1);
    long double b2 = (y11 - m2*x11);

    if(abs(m1-m2) < thresh){
        if(abs(b1-b2) < thresh){
            std::cout<<"coincident"<<"\n";
        }else{
            std::cout<<"parallel"<<"\n";
        }
        return 0;
    }else{
        long double ms = m1 - m2;
        long double bs = b1 - b2;
        long double x = -bs/ms;
        long double y = m1*x+b1;
        x = std::round(x*10e6)/10e6;
        y = std::round(y*10e6)/10e6; 
        std::cout<<std::fixed<<std::setprecision(6)<<x<<" "<<y<<"\n";


    }


    return 0;
}