#include <bits/stdc++.h>
typedef std::pair<int,int> ipair;

int N;


std::vector<ipair> adj[1010];
void djk(){
    
    std::priority_queue<ipair> pq;
    int dist[1010], prev[1010];
    for(int i = 2; i < 1010; i++){
        dist[i] = __INT_MAX__;
        prev[i] = -1;    
    }
    dist[1] = 0;
    prev[1] = 1;
    
    pq.push(std::make_pair(0,1));
    
    while(!pq.empty()){
        ipair next = pq.top();
        pq.pop();
        int n = next.second;
        
        for(ipair p : adj[n]){
            
            int alt = dist[n] + p.first;
            int dn = p.second;
            //std::cout<<"node: "<<n<<" dest: "<<dn<<" weight: "<<p.first<<"\n";
        
            if(alt < dist[dn]){
                dist[dn] = dist[n] + p.first;
                prev[dn] = n;
                pq.push(p);
            }
        }
    }
    for(int i = 1; i < N+1; i++){
        std::cout<<(dist[i] == __INT_MAX__ ? -1 : dist[i])<<"\n";
    }
}

int main(){
    int m;
    std::cin>>N>>m;
    
    for(int i= 0; i < m; i++){
        int a,b,w; 
        std::cin>>a>>b>>w;
        adj[a].push_back(std::make_pair(w,b));
        adj[b].push_back(std::make_pair(w,a));
    }
    djk();

    return 0;
}


