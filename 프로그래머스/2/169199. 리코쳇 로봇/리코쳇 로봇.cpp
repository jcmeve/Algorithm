#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
vector<string>* g_board;
bool IsOutOfBorder(int y, int x) {
    return (x < 0 || x >= (*g_board)[0].size() || y < 0 || y >= g_board->size());
}


int solution(vector<string> board) {
    g_board = &board;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    int y = 0, x = 0;
    for (; y < board.size(); ++y) {
        for (x=0; x < board[0].size(); ++x) {
            if (board[y][x] == 'R') goto FIND;
        }
    }
FIND:;
    queue<vector<int>> q;
    q.push({ y,x,0 });
    while (!q.empty()) {
        int y = q.front()[0];
        int x = q.front()[1];
        int cnt = q.front()[2];
        q.pop();
        if (IsOutOfBorder(y,x)||visited[y][x])
            continue;
        visited[y][x] = true;

        if (board[y][x] == 'G') {
            return cnt;
        }

        {
            int tx = x + 1, ty = y;
            while (!IsOutOfBorder(ty, tx) && board[ty][tx] != 'D') {
                ++tx;
            }
            q.push({ ty, tx - 1, cnt + 1 });
        }

        {
            int tx = x - 1, ty = y;
            while (!IsOutOfBorder(ty, tx) && board[ty][tx] != 'D') {
                --tx;
            }
            q.push({ ty, tx + 1, cnt + 1 });
        }

        {
            int tx = x, ty = y + 1;
            while (!IsOutOfBorder(ty, tx) && board[ty][tx] != 'D') {
                ++ty;
            }
            q.push({ty - 1, tx, cnt + 1});
        }

        {
            int tx = x, ty = y - 1;
            while (!IsOutOfBorder(ty, tx) && board[ty][tx] != 'D') {
                --ty;
            }
            q.push({ ty + 1, tx, cnt + 1 });
        }


    }

    return -1;

}