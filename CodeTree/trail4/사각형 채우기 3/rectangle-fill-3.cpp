#include <iostream>
using namespace std;

long long cache[1001];
long long cache2[1001];
long long f(long long n){
    if(n==1||cache[n]) return cache[n];
    cache2[n] = (f(n-1) + cache2[n-1])%1000000007;
    return cache[n] = (f(n-1)*2+f(n-2)+2*cache2[n-1])%1000000007;

}

int main() {
    cache[0] =0;
    cache[1] =2;
    cache[2] = 7;
    cache2[0] = 0;
    cache2[1] = 1;
    cache2[2] = 3;

    long long N;
    cin>>N;
    cout<<f(N);

    return 0;
}