#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int a, int b) {
    for(int i =2; i <= min(a,b); ++i){
        if(a%i == 0 && b%i == 0){
            a/=i;
            b/=i;
            --i;
        }
    }
    while(b%2 == 0){
        b/=2;
    }
    while(b%5 == 0){
        b/=5;
    }
    return b == 1? 1:2;
    
}