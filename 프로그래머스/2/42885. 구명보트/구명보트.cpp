#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());
    int l = 0;
    int r = people.size() - 1;
        
    for(;;) {
        
        if(l > r){
            break;
        }
        answer++;
        int remain_weight = limit - people[l];
        ++l;
        if(remain_weight>=people[r]){
            --r;
        }
        
    }
    return answer;
}