#include <string>
#include <vector>

using namespace std;

long long cache[2001];
long long solution(int n) {
    if( n == 1)
        return 1;
    if(n == 2)
        return 2;
    if(cache[n] == 0)
        cache[n] = (solution(n-2)%1234567 + solution(n-1)%1234567)%1234567;
    return cache[n]; 
}