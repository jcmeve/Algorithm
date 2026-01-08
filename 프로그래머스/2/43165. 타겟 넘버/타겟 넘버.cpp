#include <string>
#include <vector>

using namespace std;
int g_size = 0;
int answer = 0;
vector<int> *g_numbers;
int g_target;

void f(int currSum, int idx){
    if(idx == g_size-1){
        if(currSum+(*g_numbers)[idx] == g_target){
            answer++;
        }
        if(currSum-(*g_numbers)[idx] == g_target){
            answer++;
        }
        return;
    }
    
    f(currSum+(*g_numbers)[idx],idx+1);
    f(currSum-(*g_numbers)[idx],idx+1);
}


int solution(vector<int> numbers, int target) {
    g_size = numbers.size();
    g_numbers = &numbers;
    g_target = target;
    
    f(0,0);
    
    
    return answer;
}