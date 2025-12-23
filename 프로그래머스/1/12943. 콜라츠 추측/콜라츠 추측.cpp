#include <string>
#include <vector>

using namespace std;

int solution(int _num) {
    long long num = _num;
    for(int i = 0; i < 500; ++i){
        if(num == 1)
            return i;
        
        if(num%2){
            num*=3;
            num+=1;
        }else{
            num/=2;
        }
        
    }
    return -1;
}