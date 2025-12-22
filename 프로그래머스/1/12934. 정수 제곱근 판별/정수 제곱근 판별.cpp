#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long x = sqrt(n);
    if(x*x == n){
        return (x+1)*(x+1);
    }else if((x+1)*(x+1) == n){
        return (x+2)*(x+2);
    }
    return -1;

}