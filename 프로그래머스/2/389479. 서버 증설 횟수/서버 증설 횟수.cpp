#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<int> q;
    for(int i = 0; i < players.size(); ++i){
        while(!q.empty() && q.front()<=i-k) q.pop();
        
        while(players[i] / m > q.size()){
            q.push(i);
            ++answer;
        }
    }
    return answer;
}