#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int bottle=n;
    for(;;){
        int ret = bottle/a*b;
        if(ret == 0){
            break;
        }
        answer += ret;
        bottle= bottle%a + ret;
        
    }
    
    return answer;
}