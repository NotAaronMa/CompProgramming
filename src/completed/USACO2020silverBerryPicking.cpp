#include <bits/stdc++.h>
typedef long long ll;
int N,K;
int tree[1010];

bool greater(int a,int b){
    return a >b;
}

int main(){
    std::cin>>N>>K;
    for(int i = 1; i <= N; i++){
        std::cin>>tree[i];

    }

    int mx = 0;
    for(int x = 1; x < 1001; x++){
        int cnt = 0;
        for(int i = 1; i <= N; i++){
            cnt += tree[i]/x;
        }
        if(cnt < K/2){
            break;
        }else if(cnt >= K) {
            mx = std::max((K/2)*x,mx);
        }else{
            std::priority_queue<int> s;
            for(int i = 1; i <= N; i++){
               s.push(tree[i] % x); 
            }
            int ans=0;
            for(int i = 0; i < K-cnt; i++){
                ans += s.top(); s.pop();
            }
            ans += (cnt-K/2)*x;
            mx = std::max(mx,ans);

        }
    }
    std::cout<<mx;

}