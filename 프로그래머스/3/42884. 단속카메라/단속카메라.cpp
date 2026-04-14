#include <string>
#include <vector>
#include <queue>
using namespace std;
struct comp {
    bool operator () (const vector<int>& l, const vector<int>& r) {
        if (l[1] != r[1]) {
            return l[1] > r[1];
        }
        return l[0] > r[0];
    }
};

int solution(vector<vector<int>> routes) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, comp> q(routes.begin(), routes.end());
    int curr = -30000;
    while (!q.empty()) {
        ++answer;
        curr = q.top()[1];
        while (q.top()[0] <= curr)q.pop();
    }

    return answer;
}