#include <iostream>
using namespace std;

int board[101][101];

int main() {
    int N,M;
    cin>>N>>M;


    for(int i= 0; i < M; ++i){
        int a,b;
        cin>>a>>b;
        board[a][b] = 1;
        board[b][a] = -1;
    }


    for(int k = 1; k <= N; ++k){
    for(int i = 1; i <= N; ++i){
    for(int j = 1; j <= N; ++j){
        if(i == j){
            continue;
        }
        else if(i == k){
            board[i][j] = board[k][j];
        }
        else if(j==k){
            board[i][j] = board[i][k];
        }
        else if(board[i][k] == board[k][j] && board[i][k] != 0){
            board[i][j] = board[i][k];
            
        }
    }
    }
    }


    for(int i =1; i <= N; ++i){
        int cnt = 0;
        for(int j = 0; j <= N; ++j){
            if(board[i][j]!=0 || i==j)++cnt;
        }
        cout<<N-cnt<<endl;
    }




    return 0;
}