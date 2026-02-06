#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer(sources.size());
    vector<vector<int>> g(n+1);
    for(vector<int>& road : roads){
        g[road[0]].push_back(road[1]);
        g[road[1]].push_back(road[0]);
    }
    
    vector<int> dists(n+1,-1);
    queue<int> q;
    
    q.push(destination);
    dists[destination] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int next : g[curr]){
            if(dists[next] != -1) continue;
            q.push(next);
            dists[next] = dists[curr]+1;
        }
    }
    for(int i =0; i < sources.size(); ++i){
        answer[i] = dists[sources[i]];
    }
    
    return answer;
}