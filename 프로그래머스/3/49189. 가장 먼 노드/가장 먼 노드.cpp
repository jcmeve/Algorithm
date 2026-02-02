#include <string>
#include <vector>
#include <queue>
using namespace std;
int d[20001];
int M;
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> g(n+1,vector<int>());

    for (auto& v : edge) {
        g[v[0]].push_back(v[1]);
        g[v[1]].push_back(v[0]);
    }

    queue<int> targets;
    targets.push(1);
    for (; targets.size();) {
        int curr = targets.front();
        targets.pop();
        for (int v : g[curr]) {
            if (d[v] == 0) {
                d[v] = d[curr] + 1;
                M = max(d[v], M);
                targets.push(v);
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        if (d[i] == M)
            ++answer;
    }
    return answer;
}
