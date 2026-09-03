#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N,M;
    cin>>N>>M;
    
    vector<vector<int>> board(N+1,vector<int>(N+1,987654321/2));
    int v1,v2,e;
    cin>>v1>>v2>>e;
    for(int i =0; i < M; ++i){
        int a,b,c;
        cin>>a>>b>>c;
        board[a][b] = c;
        board[b][a] = c;
    }
    for(int i =0; i < N; ++i) board[i][i] = 0;


    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
        }
    }

    int answer = 987654321/2;
    for(int i = 0; i < N; ++i){
        int dist = board[v1][i] + board[v2][i] + board[i][e];
        answer = min(answer, dist);

    }
    if(answer >= 987654321/2){
        cout<<-1;
    }
    else{
        cout<<answer;
    }

    return 0;
}