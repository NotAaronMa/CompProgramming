#include <bits/stdc++.h>
#define inf __INT_MAX__ -100000
using namespace std;
typedef tuple<int,int,int> triple;

int K,N,M;

vector<triple> adj[2010];
void djk(int s, int d){
    priority_queue<triple> q;
    long long dist[2020][202];
    triple prev[2020];

    for(int i = 0; i < 2020;i++){
        for(int j = 0; j < 202; j++){
            dist[i][j] = inf ;
        }
    }
    for(int i = 0; i < 202; i++){
        dist[s][i] = 0;
    }
    q.push(make_tuple(0,0,s));


    while(!q.empty()){
        triple path = q.top();
        q.pop();
        int prev = get<2>(path);
        vector<triple> paths = adj[prev];

        for(triple p : paths){
            int w,h,d;
            
            w = get<0>(p);
            h = get<1>(p);
            d = get<2>(p);
            //cout<<"src: "<<prev<<" dest: "<<d<<"\n";
            /*
            possibly K-w instead of K-h-1
            */
            bool flag  = false;
            for(int i = 0; i < K - h; i++){
                int alt = w + dist[prev][i];
                if(alt < dist[d][i+h]){
                    dist[d][i+h] = alt;
                    flag = true;
                }
            }
            if(flag) q.push(p);
        }
    }
    int md = inf;
    for(int i = 0; i < K+1; i++){
        md = dist[d][i] < md ? dist[d][i]: md;
    }
    cout<<(md == inf?-1:md);

} 


int main(){
    cin>>K>>N>>M;

    
    for(int i = 0; i < M; i++){
        int a,b,t,h;
        cin>>a>>b>>t>>h;
        adj[a].push_back(make_tuple(t,h,b));
        adj[b].push_back(make_tuple(t,h,a));
    }

    int s,d;
    cin>>s>>d;

    djk(s,d);
    return 0;
    
}

