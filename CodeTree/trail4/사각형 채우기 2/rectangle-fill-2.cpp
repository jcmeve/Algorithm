#include <iostream>
using namespace std;

int cache[1001];

int f(int n){
    if(n==0 || cache[n]) return cache[n];
    return cache[n] = (2*f(n-2)+f(n-1))%10007;
}

int main() {
    int N;
    cin>>N;
    cache[1] = 1;
    cache[2] = 3;
    cout<<f(N);


    return 0;
}