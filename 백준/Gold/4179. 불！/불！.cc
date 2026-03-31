#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int dirR[4] = { 0,0,1,-1 };
int dirC[4] = { 1,-1,0,0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r, c;
    cin >> r >> c;
    vector<vector<int>> map(r, vector<int>(c, INT_MAX));

    queue<pair<int, int>> fire;
    queue<pair<int, int>> jihun;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            char temp;
            cin >> temp;
            switch (temp)
            {
            case 'J':
                jihun.push({ i,j });
                break;
            case 'F':
                fire.push({ i,j });
                map[i][j] = 0;
                break;
            case '#':
                map[i][j] = -1;
                break;
            default://empty
                break;
            }
        }
    }



    int turn = 0;
    while (!fire.empty()) {
        turn++;
        int size = fire.size();
        for (int i = 0; i < size; ++i) {
            pair<int, int> fire_pos = fire.front();
            fire.pop();
            for (int j = 0; j < 4; ++j) {
                int nr = fire_pos.first + dirR[j];
                int nc = fire_pos.second + dirC[j];

                if (nr >= 0 && nr < r && nc >= 0 && nc < c) {
                    if (map[nr][nc] == INT_MAX ) {
                        map[nr][nc] = turn;
                        fire.push({ nr, nc });
                    }
                }
            }
        }
    }

    turn = 0;
    if (!jihun.empty()) {
        map[jihun.front().first][jihun.front().second] = -1;
    }
    while (!jihun.empty()) {
        ++turn;
        int size = jihun.size();
        for (int i = 0; i < size; ++i) {
            pair<int, int> cur = jihun.front();
            jihun.pop();

            if (cur.first == 0 || cur.first == r - 1 || cur.second == 0 || cur.second == c - 1) {
                cout << turn;
                return 0;
            }

            for (int i = 0; i < 4; ++i) {
                int nr = cur.first + dirR[i];
                int nc = cur.second + dirC[i];

                if (nr >= 0 && nr < r && nc >= 0 && nc < c) {
                    if (map[nr][nc] != -1) {
                        if (map[nr][nc] > turn) {
                            jihun.push({ nr, nc });
                            map[nr][nc] = -1;
                        }
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}