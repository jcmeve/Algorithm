#include <iostream>
using namespace std;

int cache[20];

int f(int n){
    if(cache[n]) return cache[n];
    int ret = 0;
    for(int i =0;i<n;++i){
        ret += f(i)*f(n-i-1);
    }
    return cache[n] = ret;
    
}

int main() {
    int N;
    cin>>N;
    cache[0] = 1;
    cache[1] = 1;
    cache[2] = 2;
    cout<<f(N);
    return 0;
}