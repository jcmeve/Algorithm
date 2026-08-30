#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

int f(int n){
    if(arr[n]){
        return arr[n];
    }
    return arr[n] = f(n-2)+f(n-1);
}


int main() {
    int N;
    cin>>N;
    arr = vector<int>(N+1,0);
    arr[1] = 1;
    arr[2] = 1;
    cout<<f(N);
    
    return 0;
}