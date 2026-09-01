#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N,M;
    cin>>N>>M;
    vector<vector<int>> dist(N,vector<int>(N,98765432));
    for(int i =0; i < N; ++i) dist[i][i] = 0;
    
    for(int i = 0; i < M; ++i){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a-1][b-1] = min(dist[a-1][b-1], c);
    }


    for(int k =0; k < N; ++k){
        for(int i =0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    for(int i =0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(dist[i][j] == 98765432) cout<<-1<<" ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}