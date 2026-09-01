#include <iostream>
using namespace std;
int m[101][101];

int main() {
    int N;
    cin>>N;
    for(int i =0; i < N; ++i){
        for(int j =0; j < N; ++j){
            cin>>m[i][j];
        }
    }

    for(int i = 0; i<N; ++i) m[i][i] = 1;

    for(int k =0; k < N; ++k){    
        for(int i =0; i < N; ++i){
            for(int j =0; j < N; ++j){
                m[i][j] |= (m[i][k]) & (m[k][j]);
            }
        }
    }

    for(int i =0; i < N; ++i){
        for(int j =0; j < N; ++j){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}