#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

struct Node {
    int cost, y, x, dir;
    
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

int solution(vector<vector<int>> board) {
    
    vector<vector<vector<int>>> d(board.size(),vector<vector<int>>(board[0].size(),{INT_MAX,INT_MAX,INT_MAX,INT_MAX}));
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    
    for(int i =0; i<4; ++i)d[0][0][i] = 0;
    
    if (board[1][0] == 0) {
        d[1][0][1] = 100;
        pq.push({100, 1, 0, 1});
    }
    if (board[0][1] == 0) {
        d[0][1][3] = 100;
        pq.push({100, 0, 1, 3});
    }
    
    while(!pq.empty()){
        Node curr = pq.top();pq.pop();
        for(int i =0; i < 4; ++i){
            pair<int,int> next = {curr.y+dy[i], curr.x+dx[i]};
            
            if(next.first<0 || next.first >= board.size() || next.second<0 || next.second>= board.size()) continue;
            if(board[next.first][next.second] == 1) continue;
            
            int m = curr.cost + 100;
            if(curr.dir != i) {
                m += 500;
            }
            
            if(d[next.first][next.second][i] > m){
                d[next.first][next.second][i] = m;
                pq.push({m,next.first,next.second,i});
            }
        }
    }
    
    int answer = INT_MAX;
    for(int j =0; j < 4; ++j){
        answer = min(answer, d[board.size()-1][board[0].size()-1][j]);            
    }

    return answer;
}