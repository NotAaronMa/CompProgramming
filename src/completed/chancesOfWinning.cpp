#include <bits/stdc++.h>
typedef long long ll;

int T,G;
int point[6];
bool play[6][6];
std::vector<std::pair<int,int>> gr;


bool ismax (int* arr, int n){
    int cnt = 0;

    for(int i = 1; i <= 4; i++){
        if(arr[n] <= arr[i] && i != n){
            return false;
        }
    }
    return true;
}

int solve(int n, int* points){
    
    if(n == gr.size()){
        return ismax(points,T);
    }else{
        int p[3][5];
        std::pair<int,int>g = gr[n];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j <=4;j++){
                p[i][j] = points[j];
            }
        }
        p[0][g.first] += 3;
        p[1][g.second] += 3;
        p[2][g.first] ++;
        p[2][g.second] ++;
        return solve(n+1, p[0]) + solve(n+1,p[1]) + solve(n+1, p[2]);
    }
    

}



int main(){
    std::cin>>T>>G;
    for(bool* i : play){
        for(int j = 0; j < 6; j++){
            i[j] = false;   
        }
    }
    point[0] = -1;
    for(int i = 0; i < G;i++){
        int s,s1, t,t1;
        std::cin>>t>>t1>>s>>s1;
        play[t][t1] = true;
        play[t1][t] = true;
        if(s == s1){
            point[t] ++;
            point[t1] ++;
        }else if(s > s1){
            point[t]+=3;
        }else{
            point[t1] += 3;
        }
    } 


    for(int i = 1; i <= 4; i++){
        for(int j = i+1; j <=4; j++){
            if(!play[i][j]){
                gr.push_back(std::make_pair(i,j));
            }
        }
    }


    std::cout<<solve(0,point);

    return 0;
}