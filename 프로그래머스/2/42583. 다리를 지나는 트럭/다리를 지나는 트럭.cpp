#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;

    int curr_weights = 0;
    queue<pair<int, int>> trucks_on_bridge;//weight,remain

    for (int i = 0; i < truck_weights.size(); ++i) {


        if (curr_weights + truck_weights[i] > weight || 
            (!trucks_on_bridge.empty() && trucks_on_bridge.front().second == answer)) {
            pair<int, int> t = trucks_on_bridge.front();
            curr_weights -= t.first;
            answer = t.second;
            trucks_on_bridge.pop();
            --i;
        }
        else {
            curr_weights += truck_weights[i];
            trucks_on_bridge.push(pair<int, int>(truck_weights[i], answer + bridge_length));
            cout << answer << " ~ " << answer + bridge_length << endl;
            
            answer++;
        }
    }

    answer = trucks_on_bridge.back().second;

    return answer;
}
