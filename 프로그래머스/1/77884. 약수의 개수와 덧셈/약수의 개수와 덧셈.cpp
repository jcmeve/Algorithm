#include <string>
#include <vector>

using namespace std;
int cache[1001];
int solution(int left, int right) {
    int answer = 0;
    
    for(int i =1; i <= 1000; ++i){
        for(int j = 1; j*i<=1000; ++j){
            ++cache[i*j];
        }
    
    }
    for(int i =left; i <= right; ++i){
        if(cache[i]%2){
            answer-=i;
        }else{
            answer+=i;
        }
    }
    
    return answer;
}