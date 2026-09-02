#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N,M,P,Q;
    cin>>N>>M>>P>>Q;

    vector<vector<int>> g(N,vector<int>(N, 987654321));
    for(int i =0; i < N; ++i) g[i][i] = 0;

    for(int i = 0; i < M; ++i){
        int a,b,c;
        cin>>a>>b>>c;
        if(c<g[a-1][b-1]){
            g[a-1][b-1] = c;
        }
    }

    

    for(int k = 0; k < N;  ++k){
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(g[i][k] != 987654321 && g[k][j] != 987654321){
                    int curr_dist = g[i][k]+g[k][j];
                    if(curr_dist < g[i][j])
                        g[i][j] = curr_dist;
                }
            }
        }
    }

    long long sum = 0;
    int nr = 0;
    for(int i =0; i < Q; ++i){
        int a,b;
        cin>>a>>b;
        int minDist = 987654321;
        for(int i = 0; i < P; ++i){
            minDist = min(minDist, g[a-1][i]+g[i][b-1]);
        }
        if(minDist < 987654321){
            ++nr;
            sum+=minDist;
        }
    }
    cout<<nr<<endl<<sum;

    

    return 0;
}