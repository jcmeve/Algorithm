#include <iostream>
#include <vector>
using namespace std;



int main() {
    // Please write your code here.


    int N,M;
    cin>>N>>M;
    vector<vector<int>> g(N,vector<int>(N,987654321/2));


    for(int i =0; i<M; ++i){
        int a,b,c;
        cin>>a>>b>>c;
        g[a-1][b-1] = c;
    }

    for(int k = 0; k < N; ++k){
    for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    }
    }
    }

    int answer = 987654321;
    for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
        answer = min(answer, g[i][j] + g[j][i]);
    }
    }
    cout<<answer;

    return 0;
}