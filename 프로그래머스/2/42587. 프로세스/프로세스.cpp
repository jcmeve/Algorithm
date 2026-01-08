#include <string>
#include <vector>

using namespace std;
int cache[10];
int solution(vector<int> priorities, int location) {
    int answer = 0;
    for(int i =0; i < priorities.size(); ++i){
        cache[priorities[i]]++;
    }
    
    int currPrio = 10;
    int Idx = 0;
    for(;;){
        
        for(int i = currPrio-1; i>=0; --i){
            if(cache[i] != 0){
                currPrio = i;
                break;
            }
        }
        if(currPrio == priorities[location])
            break;
        
        for(int i = Idx; i != (Idx+1)%priorities.size(); --i){
            if(i == -1)
                i = priorities.size()-1;
            if(priorities[i] == currPrio){
                Idx = i;
                break;
            }
        }

    }
    
    int dst = Idx-1;
    if( Idx == -1)
        dst = priorities.size()-1;
    for(int i = Idx; i != dst;++i){
        if(i == priorities.size()){
            i = 0;
        }
        if(priorities[i] == priorities[location]){
            answer++;
            if( i == location){
                break;
            }
        }
    }
    
    for(int i = priorities[location]+1; i < 10; ++i){
        answer += cache[i];
    }
    
    return answer;
}