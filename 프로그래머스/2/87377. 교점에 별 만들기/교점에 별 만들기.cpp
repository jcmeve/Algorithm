#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<long long,long long>> vertices;
    long long minX = LLONG_MAX;
    long long maxX = -LLONG_MAX;
    long long minY = LLONG_MAX;
    long long maxY = -LLONG_MAX;
    for(int i =0; i < line.size();++i){
        for(int j =i+1; j < line.size();++j){
            long long d = (long long)line[i][0]*line[j][1] - (long long)line[i][1]*line[j][0];
            if(d == 0) continue;
            long long x = (long long)line[i][1]*line[j][2]-(long long)line[i][2]*line[j][1];
            if(x%d) continue;
            long long y = (long long)line[i][2]*line[j][0]-(long long)line[i][0]*line[j][2];
            if(y%d) continue;
            
            x /=d;
            y /=d;
            vertices.push_back({x,y});
            minX = min(minX,x);
            maxX = max(maxX,x);
            minY = min(minY,y);
            maxY = max(maxY,y);
        }        
    }

    answer.assign(maxY-minY+1,string(maxX-minX+1,'.'));

    for(auto& vertex : vertices){
        answer[maxY-vertex.second][vertex.first-minX] = '*';
    }
    
    return answer;
}