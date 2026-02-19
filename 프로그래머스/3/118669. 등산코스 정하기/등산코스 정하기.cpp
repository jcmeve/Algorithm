#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer; 
    vector<vector<pair<int,int>>> g(n+1);
    vector<int> min_intensity(n+1,987654321);
    for(auto& path : paths){
        g[path[0]].push_back({path[1],path[2]});
        g[path[1]].push_back({path[0],path[2]});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for(int gate : gates){
        q.push({0,gate});
    }
    
    while(!q.empty()){
        int curr_intensity = q.top().first;
        int curr_v = q.top().second;
        q.pop();
        if(min_intensity[curr_v] < curr_intensity) continue;
        if(find(summits.begin(),summits.end(),curr_v) != summits.end()) continue;
        
        for(auto p : g[curr_v]){
            if(find(gates.begin(),gates.end(),p.first) != gates.end()) continue;
            
            int temp_intensity = max(curr_intensity,p.second);
            if(min_intensity[p.first] > temp_intensity){
                min_intensity[p.first] = temp_intensity;
                q.push({temp_intensity,p.first});
            }
        }
    }
    sort(summits.begin(), summits.end());
    for (int summit : summits) {
        if (answer.empty() || min_intensity[summit] < answer[1]) {
            answer = {summit,min_intensity[summit]};
        }
    }
    
    return answer;
}