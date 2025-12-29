#include <string>
#include <vector>

using namespace std;
int cache[100001];
int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i = 1; i < 100001;++i ){
        for(int j = 1; i*j < 100001; ++j){
            ++cache[i*j];
        }
    }
    for(int i = 1; i <= number; ++i){
        if(cache[i]>limit){
            answer+= power;
        }else{
            answer+=cache[i];
        }
    }
    
    return answer;
}