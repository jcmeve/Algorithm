#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> map(rows, vector<int>(columns, 0));
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < columns; ++x) {
            map[y][x] = y * columns + x+1;
        }
    }


    for (vector<int>& query : queries) {
        int y1 = query[0]-1;
        int x1 = query[1]-1;
        int y2 = query[2]-1;
        int x2 = query[3]-1;

        int x = x1;
        int y = y1;
        int m = 10001;
        for (; y < y2; ++y) {
            m = min(m, map[y][x]);
            m = min(m, map[y + 1][x]);
            swap(map[y][x], map[y + 1][x]);
        }
        for (; x < x2; ++x) {
            m = min(m, map[y][x]);
            m = min(m, map[y][x + 1]);
            swap(map[y][x], map[y][x + 1]);
        }
        for (; y > y1; --y) {
            m = min(m, map[y][x]);
            m = min(m, map[y - 1][x]);
            swap(map[y][x], map[y - 1][x]);
        }
        for (; x > x1 + 1; --x) {
            m = min(m, map[y][x]);
            m = min(m, map[y][x - 1]);
            swap(map[y][x], map[y][x - 1]);
        }
        answer.push_back(m);
    }

    return answer;
}