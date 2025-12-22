#include <string>
#include <vector>

using namespace std;
int cache[10];
long long solution(long long n) {
    long long answer = 0;
    for(;n>0;n/=10)
        ++cache[n%10];
    for(int i = 9; i >= 0; --i){
        for(int j=0; j<cache[i]; ++j){
            answer*=10;
            answer+=i;
        }
    }
    return answer;
}