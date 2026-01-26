#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool compare(vector<int> a, vector<int> b){
    if(a[0] == b[0])
        return a[1]<b[1];
    return a[0]<b[0];
}

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), compare);
    int minX = 987654321;
    int answer = 0;
    for(int i = 0; i < targets.size(); ++i){
        if(minX <= targets[i][0]){
            ++answer;
            minX = 987654321;
        }
        minX = minX<targets[i][1]?minX:targets[i][1];
    }
    return answer+1;
}