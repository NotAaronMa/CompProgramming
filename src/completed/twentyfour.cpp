#include <bits/stdc++.h>




int cards[4];
int mm;

void chk(int c){

    if(c <= 24){
        mm = std::max(c,mm);
    }


}

int solve(int cur,int next, int id){
    if(id == 3){
        chk(cur+next);
        chk(cur-next);
        chk(cur*next);
        if( next != 0 && cur%next == 0){
            chk(cur/next);
        }
        
   
    }else{
        solve(cur+next, cards[id+1], id+1);
        solve(cur*next, cards[id+1], id+1);
        solve(cur-next, cards[id+1], id+1);
        if( next != 0 && cur%next == 0 ){
            solve(cur/next, cards[id+1], id+1);
        }
        solve(cur, next+cards[id+1], id+1);
        solve(cur, next*cards[id+1], id+1);
        solve(cur, next-cards[id+1], id+1);
        if(cards[id+1] != 0 && next % cards[id+1] == 0 ){
            solve(cur, next/cards[id+1], id+1);
        }

    }

    return 0;
}


int main(){

    int q;std::cin>>q;

    for(int i = 0; i < q; i++){
        for(int j = 0; j < 4; j++){
            std::cin>>cards[j];
        }
        std::sort(cards,cards+4);
        mm =0;
        do{
            solve(cards[0],cards[1],1);
        }while(std::next_permutation(cards,cards+4));
        std::cout<<mm<<"\n";
    }


}