#include<iostream>
using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
//    f(x) = -(h/w)x + h 
    
    for( int x = 1 ; x<w ; x++){
        int temp = (int)(-((double)h/w)*x + h) ;
        
        answer += temp;
    }
    answer *= 2;
    return answer;
}