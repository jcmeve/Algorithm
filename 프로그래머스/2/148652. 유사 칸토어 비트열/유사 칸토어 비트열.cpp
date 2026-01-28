#include <string>
#include <vector>

using namespace std;



int solution(int n, long long l, long long r) {
    int answer = 0;
    
    
    //1
    //11011
       // ()      (5+2)*5~(5+2)*5+4    (10+0)*5~(10+0)*5+4  
    //11011 11011 00000 11011 11011
    //정확히 5배로 커짐
            
    for(long long i = l-1;i<=r-1;++i){
        long long temp = i;
        while(temp){
            if(temp%5 ==2){
                goto FAIL;
            }
            temp/=5;
        }
        ++answer;
        FAIL:;
        
    }
    return answer;
}