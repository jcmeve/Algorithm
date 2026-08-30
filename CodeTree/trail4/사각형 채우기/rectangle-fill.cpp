#include <iostream>
using namespace std;

int cache[1001];

int f(int n){
    if(n==0||cache[n]) return cache[n];
    return cache[n] = (f(n-2)+f(n-1))%10007;
}

int main() {
    
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 2;

    int N;
    cin>>N;
    cout<<f(N);

    return 0;
}