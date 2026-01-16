#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long squared_d = (long long)d*d;
    for(long long y = 0; y<=d;y+=k){
        long long squared_y = y*y;
        answer += (sqrtl(squared_d-squared_y))/k+1;
    }
    return answer;
}