#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int mapSize = maps.size() * maps[0].size();
    int mapWidth = maps[0].size();
    for (int idx = 0; idx < mapSize; ++idx) {
        if (maps[idx / (mapWidth)][idx % (mapWidth)] != 'X') {
            queue<int> q;
            q.push(idx);
            int sum = 0;
            sum+=maps[idx / mapWidth][idx % mapWidth]-'0';
            maps[idx / mapWidth][idx % mapWidth] = 'X';
            
            while (!q.empty()) {
                int currIdx = q.front();
                q.pop();
                if (currIdx - 1 >= 0 && 
                    (currIdx/mapWidth==(currIdx-1)/mapWidth) && 
                    maps[(currIdx - 1) / mapWidth][(currIdx - 1) % mapWidth] != 'X') {
                    sum += maps[(currIdx -1) / mapWidth][(currIdx -1) % mapWidth]-'0';
                    maps[(currIdx -1) / mapWidth][(currIdx -1) % mapWidth] = 'X';
                    q.push(currIdx - 1);
                }
                if (currIdx + 1 < mapSize && 
                    (currIdx / mapWidth == (currIdx + 1) / mapWidth) && 
                    maps[(currIdx + 1) / mapWidth][(currIdx + 1) % mapWidth] != 'X') {

                    sum+=maps[(currIdx +1) / mapWidth][(currIdx +1) % mapWidth]-'0';
                    maps[(currIdx +1) / mapWidth][(currIdx +1) % mapWidth] = 'X';
                    q.push(currIdx + 1);
                }
                if (currIdx - mapWidth >= 0 && maps[(currIdx - mapWidth) / mapWidth][(currIdx - mapWidth) % mapWidth] != 'X') {
                    sum+=maps[(currIdx - mapWidth) / mapWidth][(currIdx - mapWidth) % mapWidth]-'0';
                    maps[(currIdx - mapWidth) / mapWidth][(currIdx - mapWidth) % mapWidth] = 'X';
                    q.push(currIdx - mapWidth);
                }
                if (currIdx + mapWidth < mapSize && maps[(currIdx + mapWidth) / mapWidth][(currIdx + mapWidth) % mapWidth] != 'X') {
                    sum+=maps[(currIdx + mapWidth) / mapWidth][(currIdx + mapWidth) % mapWidth]-'0';
                    maps[(currIdx + mapWidth) / mapWidth][(currIdx + mapWidth) % mapWidth] = 'X';
                    q.push(currIdx + mapWidth);
                }
            }
            answer.push_back(sum);
        }
    }
    sort(answer.begin(), answer.end());
    if(answer.empty())return{-1};
    return answer;
}
