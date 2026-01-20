#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<string> maps) {
    int answer = 0;
    int sx, sy;
    int lx, ly;
    int ex, ey;
    for (int y = 0; y < maps.size(); ++y) {
        for (int x = 0; x < maps[0].size(); ++x) {
            switch (maps[y][x]) {
            case 'S':sx = x; sy = y;
                break;
            case 'L':lx = x; ly = y;
                break;
            case 'E':ex = x; ey = y;
                break;

            }
        }
    }

    {
        vector<vector<int>> temp_maps(maps.size(), vector<int>(maps[0].size(), 0));
        queue<vector<int>> q;//idx,steps
        q.push({ sy,sx,0 });
        while (!q.empty()) {
            auto v = q.front();
            q.pop();

            int y = v[0];
            int x = v[1];
            int steps = v[2];

            if (y < 0 || y >= maps.size() || x < 0 || x >= maps[0].size())
                continue;
            if (maps[y][x] == 'X') {
                continue;
            }
            if (maps[y][x] == 'L') {
                answer += steps;
                break;
            }

            if (temp_maps[y][x]!= 0 && temp_maps[y][x] <= steps) {
                continue;
            }
            temp_maps[y][x] = steps;
            q.push({ y - 1,x,steps + 1 });
            q.push({ y + 1,x,steps + 1 });
            q.push({ y,x - 1,steps + 1 });
            q.push({ y,x + 1,steps + 1 });

        }

    }
    if (answer == 0)
        return -1;

    {
        vector<vector<int>> temp_maps(maps.size(), vector<int>(maps[0].size(), 0));
        queue<vector<int>> q;//idx,steps
        q.push({ ly,lx,0 });
        while (!q.empty()) {
            auto v = q.front();
            q.pop();

            int y = v[0];
            int x = v[1];
            int steps = v[2];

            if (y < 0 || y >= maps.size() || x < 0 || x >= maps[0].size())
                continue;
            if (maps[y][x] == 'X') {
                continue;
            }
            if (maps[y][x] == 'E') {
                return answer + steps;
            }

            if (temp_maps[y][x] != 0 && temp_maps[y][x] <= steps) {
                continue;
            }
            temp_maps[y][x] = steps;
            q.push({ y - 1,x,steps + 1 });
            q.push({ y + 1,x,steps + 1 });
            q.push({ y,x - 1,steps + 1 });
            q.push({ y,x + 1,steps + 1 });

        }
    }

    return -1;


}
