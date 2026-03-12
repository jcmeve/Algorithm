#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
vector<vector<pair<int,int>>> g;

vector<int> f(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> ret(g.size(), INT_MAX);
    ret[start] = 0;
    q.push({ 0,start });
    while (!q.empty()) {
        int d = q.top().first;
        int CurrNode = q.top().second;
        q.pop();

        for (auto& pair : g[CurrNode]) {
            int origin = ret[pair.first];
            ret[pair.first] = min(
                d + pair.second,
                ret[pair.first]
            );
            if (origin != ret[pair.first]) {
                q.push({ ret[pair.first], pair.first });
            }
        }
    }
    return ret;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INT_MAX;
    g = vector<vector<pair<int,int>>>(n + 1);

    for (auto& fare : fares) {
        g[fare[0]].push_back({ fare[1] ,fare[2]});
        g[fare[1]].push_back({ fare[0] ,fare[2]});
    }
    vector<int> A = f(a);
    vector<int> B = f(b);
    vector<int> S = f(s);
    for (int c = 1; c <= n; ++c) {
        int dist = A[c] + B[c] + S[c];
        if (dist < 0) continue;
        answer = min(answer, dist);
    }
    return answer;
}