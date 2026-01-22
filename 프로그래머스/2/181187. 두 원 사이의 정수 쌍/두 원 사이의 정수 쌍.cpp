#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for( long long  x = 1; x <= r2;++x){
        double max = sqrt((long long)r2*r2-x*x);
        double min;
        if(r1<x){
            min = 0;
        }
        else{
            min = sqrt((long long)r1*r1-x*x);
        }
        
        answer+=floor(max)-ceil(min)+1;
    }
    answer*=4;
    
    return answer;
}