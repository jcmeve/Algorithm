#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    int reserve_idx = 0;
    sort(lost.begin(), lost.end(), less<int>());
    sort(reserve.begin(), reserve.end(), less<int>());
    for(int i =0; i < lost.size(); ++i){
        while(reserve[reserve_idx]<lost[i]){
            reserve_idx++;
        }
        if(reserve[reserve_idx] == lost[i]){
            reserve[reserve_idx] = -1;
            lost[i] = -1;
        }    
    }
    reserve_idx = 0;
    for(int i =0; i < lost.size(); ++i){
        if(lost[i] == -1)
            continue;
        for(int j = reserve_idx; j<reserve.size(); ++j){
            if(reserve[j] == -1)
                continue;
            if(reserve[j]>lost[i]+1){
                reserve_idx = j;
                break;
            }
            if(reserve[j] >= lost[i]-1 && reserve[j] <= lost[i]+1 ){
                reserve[j] = -1;
                lost[i] = -1;
                reserve_idx = j+1;
                break;
            }

        }
        if(lost[i]!=-1)
            --answer;
    }
    
    return answer;
}