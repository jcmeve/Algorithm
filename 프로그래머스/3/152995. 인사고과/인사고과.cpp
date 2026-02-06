#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(vector<int>& a, vector<int>& b){
    if(a[0]!=b[0]) return a[0]>b[0];
    return a[1]<b[1];
}
int solution(vector<vector<int>> scores) {
    int answer = 0;
    int targetSum = scores[0][0]+scores[0][1];
    int targetScore1 = scores[0][0];
    int targetScore2 = scores[0][1];
    
    sort(scores.begin(),scores.end(),comp);
    int max2 = 0;
    for(vector<int>& score : scores){
        if(score[1] < max2) {
            if(score[0] == targetScore1 && score[1] == targetScore2)
                return -1;
            continue;
        }
        max2 = max(max2,score[1]);
        if(score[0]+score[1]>targetSum)
            ++answer;
    }
    
    
    return answer+1;
}