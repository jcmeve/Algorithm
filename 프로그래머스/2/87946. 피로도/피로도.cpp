#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int answer = -1;


void f(int k, int cnt, vector<bool>& visited, vector<vector<int>>& dungeons){
    if(cnt == visited.size()){
        answer = cnt;
        return;
    }
    for(int i =0; i < dungeons.size(); ++i){
        if(visited[i]) continue;
        if(k<dungeons[i][0]){
            answer = max(answer, cnt);
            continue;
        }
        visited[i] = true;
        f(k-dungeons[i][1], cnt+1, visited, dungeons);
        visited[i] = false;
    }
}


int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> v(dungeons.size(),false);
    f(k,0,v, dungeons);

    return answer;
}