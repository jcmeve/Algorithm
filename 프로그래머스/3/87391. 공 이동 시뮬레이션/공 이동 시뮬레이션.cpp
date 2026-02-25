#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int YDir[4] = { 0,0,-1,1 };
int XDir[4] = { -1,1,0,0 };

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = -1;
    long long mX = x, MX = x, mY = y, MY = y;
    for (int i = queries.size() - 1; i >= 0; --i) {
        //끝인 경우 -dir보다 더 멀리 있는 놈 전부 수용  
        //끝이 아닌 경우 -dir지점에 있는놈만 수용
        int dir = queries[i][0];
        int dist = queries[i][1];
        switch (dir)
        {
        case 0:
            if (mY != 0) {
                mY += dist;
                if (mY >= m) return 0;
            }
            MY = min((long long)m - 1, MY + dist);
            break;
        case 1:
            if (MY != m-1) {
                MY -= dist;
                if (MY <0) return 0;
            }
            mY = max((long long)0, mY - dist);
            break;
        case 2:
            if (mX != 0) {
                mX += dist;
                if (mX >= n) return 0;
            }
            MX = min((long long)n - 1, MX + dist);
            break;
        case 3:
            if (MX != n-1) {
                MX -= dist;
                if (MX < 0) return 0;
            }
            mX = max((long long)0, mX - dist);
            break;
        default:
            break;
        }


    }
    return (MX-mX+1)*(MY-mY+1);

}