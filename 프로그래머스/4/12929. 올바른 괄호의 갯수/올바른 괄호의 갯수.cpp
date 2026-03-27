#include <string>
#include <vector>

using namespace std;

int answer = 0;

int f(int n,int cntOpen, int cntClose){
    if(n == cntOpen && cntOpen == cntClose) {
        ++answer;
        return 1;
    }
    int ret = 0;
    if(n>=cntOpen+1)
        ret += f(n, cntOpen+1, cntClose);    
    if(cntOpen>cntClose)    
        ret += f(n, cntOpen, cntClose+1);    
    return ret;
}

int solution(int n) {
    
    return f(n,0,0);
}