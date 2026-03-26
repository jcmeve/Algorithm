#include <cmath>
int answer;
void f(int current,int cntMul, int cntAdd){
    if(current<1) return;
    if(cntAdd<cntMul*2) return;
    
    int remainMul = (cntAdd/2)-cntMul;
    int p=1;
    for(int i = 0;i<remainMul; ++i){
        p*=3;
        if(p>current) return;
    }
    
    if(current == 1) {
        if(cntMul * 2== cntAdd)
            ++answer;
        return;
    }
    
    if(current%3==0 && (cntMul+1)*2 <= cntAdd){
        f(current/3, cntMul+1, cntAdd);
    }
    f(current-1, cntMul, cntAdd+1);
}

int solution(int n) {
    answer = 0;
    f(n,0,0);
    return answer;
}