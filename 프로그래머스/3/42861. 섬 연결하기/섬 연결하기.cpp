#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int group[100];
bool comp(const vector<int>& a, const vector<int>& b){
    if(a[2]!=b[2])
       return a[2]<b[2];
    if(a[1]!=b[1])
       return a[1]<b[1];
   return a[0]<b[0];
    
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(),costs.end(),comp);
    for(int i = 0; i < n; ++i) group[i] = i;
    int cnt = 0;
    int idx = 0;
    while(cnt != n && idx<costs.size()){
        if(group[costs[idx][0]] == group[costs[idx][1]]){
            ++idx;
            continue;
        }
        //merge
        int s = group[costs[idx][0]];
        int d = group[costs[idx][1]];
        for(int i = 0; i < n; ++i){
            if(group[i] == s) group[i] = d;
        }
        ++cnt;
        answer+=costs[idx][2];
        ++idx;
    }
    
    
    return answer;
}