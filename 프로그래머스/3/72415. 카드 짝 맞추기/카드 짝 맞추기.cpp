#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;
unordered_map<int, vector<pair<int,int>>> dict;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int bfs(vector<vector<int>> board, pair<int,int> start, pair<int,int> target){
    vector<vector<int>> dist(board.size(),vector<int>(board[0].size(),987654312));
    dist[start.first][start.second] = 0;
    queue<pair<int,int>> q;
    q.push({start.first,start.second});
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        if(curr == target) 
            return dist[curr.first][curr.second];
        
        for (int i = 0; i < 4; ++i) {
            int ny = curr.first + dy[i];
            int nx = curr.second + dx[i];
            if (ny >= 0 && ny < 4 && nx >= 0 && nx < 4) {
                if (dist[ny][nx] > dist[curr.first][curr.second] + 1) {
                    dist[ny][nx] = dist[curr.first][curr.second] + 1;
                    q.push({ny, nx});
                }
            }
            ny = curr.first; nx = curr.second;
            while (ny + dy[i] >= 0 && ny + dy[i] < 4 && nx + dx[i] >= 0 && nx + dx[i] < 4) {
                ny += dy[i]; nx += dx[i];
                if (board[ny][nx] != 0) break;
            }
            if (dist[ny][nx] > dist[curr.first][curr.second] + 1) {
                dist[ny][nx] = dist[curr.first][curr.second] + 1;
                q.push({ny, nx});
            }
        }
        
    }
    
}

int f(vector<vector<int>> board, pair<int,int> start, const vector<int>& permutation, int p_idx){
    if(p_idx>=permutation.size()){
        return 0;
    }
    int curr_target = permutation[p_idx];
    int ret = 987654321;
    
    pair<int,int> p0 = dict[curr_target][0];
    pair<int,int> p1 = dict[curr_target][1];
   
    vector<vector<int>> board_no_p0 = board;
    board_no_p0[p0.first][p0.second] = 0;

    vector<vector<int>> board_cleared = board_no_p0;
    board_cleared[p1.first][p1.second] = 0;

    int dist1 = bfs(board, start, p0) + bfs(board_no_p0, p0, p1) + 2;
    ret = min(ret, dist1 + f(board_cleared, p1, permutation, p_idx + 1));
    
    vector<vector<int>> board_no_p1 = board;
    board_no_p1[p1.first][p1.second] = 0;

    int dist2 = bfs(board, start, p1) + bfs(board_no_p1, p1, p0) + 2;
    ret = min(ret, dist2 + f(board_cleared, p0, permutation, p_idx + 1));
    
    return ret;
    
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 987654321;
    set<int> s;


    for(int y = 0; y < board.size(); ++y){
        for(int x = 0; x < board[0].size(); ++x){
            if(board[y][x]){
                s.insert(board[y][x]);
                
                dict[board[y][x]].push_back({y,x});
            }
        }
    }
    
    vector<int> v(s.begin(),s.end());
    
    do{
        int ret = f(board,{r,c},v,0);
        answer = min(answer,ret);
    }while(next_permutation(v.begin(),v.end()));
    
    return answer;
}