#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool fit(vector<pair<int, int>> hole, vector<pair<int, int>> piece) {
    if (hole.size() != piece.size())
        return false;

    int minX = 100;
    int minY = 100;
    for (auto& p : hole) {
        minX = min(minX, p.second);
        minY = min(minY, p.first);
    }
    for (auto& p : hole) {
        p.first -= minY;
        p.second -= minX;
    }
    sort(hole.begin(), hole.end());

    for (int i = 0; i < 4; ++i) {
        for (auto& p : piece) {//turn
            swap(p.first, p.second);
            p.first = -p.first;
        }
        int minX=100;
        int minY=100;
        for (auto& p : piece) {
            minX = min(minX, p.second);
            minY = min(minY, p.first);
        }
        for (auto& p : piece) {
            p.first -= minY;
            p.second -= minX;
        }
        sort(piece.begin(), piece.end());
        int j;
        for (j = 0; j < hole.size(); ++j) {
            if (hole[j] != piece[j]) {
                break;
            }
        }
        if(j == hole.size())
            return true;
    }
    return false;

}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    vector<vector<pair<int, int>>> pieces;
    vector<vector<pair<int, int>>> holes;
    for (int i = 0; i < table.size(); ++i) {
        for (int j = 0; j < table[0].size(); ++j) {
            if (table[i][j] == 1) {
                pieces.push_back(vector<pair<int, int>>());
                queue<pair<int, int>> q;
                q.push({ i,j });
                vector<pair<int, int>>& target = pieces[pieces.size() - 1];
                while (!q.empty()) {
                    auto coord = q.front();
                    target.push_back({ coord.first - i, coord.second - j });
                    table[coord.first][coord.second] = 0;
                    q.pop();

                    if ((coord.first - 1 >= 0) && table[coord.first - 1][coord.second] == 1) {
                        q.push({ coord.first - 1, coord.second });
                        table[coord.first - 1][coord.second] = 0;
                    }
                    if ((coord.first + 1 < table.size()) && table[coord.first + 1][coord.second] == 1) {
                        q.push({ coord.first + 1, coord.second });
                        table[coord.first + 1][coord.second] = 0;
                    }
                    if ((coord.second - 1 >= 0) && table[coord.first][coord.second - 1] == 1) {
                        q.push({ coord.first, coord.second - 1 });
                        table[coord.first][coord.second - 1] = 0;
                    }
                    if ((coord.second + 1 < table[0].size()) && table[coord.first][coord.second + 1] == 1) {
                        q.push({ coord.first, coord.second + 1 });
                        table[coord.first][coord.second + 1] = 0;
                    }
                }
            }

            if (game_board[i][j] == 0) {
                holes.push_back(vector<pair<int, int>>());
                queue<pair<int, int>> q;
                q.push({ i,j });
                vector<pair<int, int>>& target = holes[holes.size() - 1];
                while (!q.empty()) {
                    auto coord = q.front();
                    target.push_back({ coord.first - i, coord.second - j });
                    game_board[coord.first][coord.second] = 1;
                    q.pop();
                    if ((coord.first - 1 >= 0) && game_board[coord.first - 1][coord.second] == 0) {
                        q.push({ coord.first - 1, coord.second });
                        game_board[coord.first - 1][coord.second] = 1;
                    }
                    if ((coord.first + 1 < game_board.size()) && game_board[coord.first + 1][coord.second] == 0) {
                        q.push({ coord.first + 1, coord.second });
                        game_board[coord.first + 1][coord.second] = 1;
                    }
                    if ((coord.second - 1 >= 0) && game_board[coord.first][coord.second - 1] == 0) {
                        q.push({ coord.first, coord.second - 1 });
                        game_board[coord.first][coord.second - 1] = 1;
                    }
                    if ((coord.second + 1 < game_board[0].size()) && game_board[coord.first][coord.second + 1] == 0) {
                        q.push({ coord.first, coord.second + 1 });
                        game_board[coord.first][coord.second + 1] = 1;
                    }
                }
            }
        }
    }



    vector<bool> check = vector<bool>(holes.size(), false);

    for (int i = 0; i < pieces.size(); ++i) {
        for (int j = 0; j < holes.size(); ++j) {
            if (!check[j] && fit(holes[j], pieces[i])) {
                check[j] = true;
                answer += pieces[i].size();
                break;
            }

        }
    }
    

    return answer;
}