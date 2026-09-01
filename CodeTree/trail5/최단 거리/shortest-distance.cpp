#include <iostream>
using namespace std;
int arr[100][101];
int query[10000][2];
int main() {
    int N,M;
    cin>>N>>M;

    for(int i = 0;i<N;++i){
        for(int j = 0;j<N;++j){
            cin>>arr[i][j];
        }
    }

    for(int i = 0; i < M; ++i){
        int a,b;
        cin>>a>>b;
        query[i][0] = a-1;
        query[i][1] = b-1;
    }

    for(int k = 0; k < N; ++k){
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for(int i = 0; i < M; ++i){
        cout<<arr[query[i][0]][query[i][1]]<<endl;
    }

    return 0;
}