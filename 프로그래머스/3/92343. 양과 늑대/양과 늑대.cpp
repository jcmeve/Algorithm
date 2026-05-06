#include <string>
#include <vector>
using namespace std;

vector<int>* g_info;
vector<vector<int>> g_edges;
int answer = 0;
void f(int nr_sheep,int nr_wolf, vector<int> targets) {

    answer = max(answer, nr_sheep);

    for (int i = 0; i < targets.size(); ++i) {
        int next_nr_sheep = nr_sheep;
        int next_nr_wolf = nr_wolf;
        if ((*g_info)[targets[i]] == 0) {
            ++next_nr_sheep;
        }
        else {
            ++next_nr_wolf;
        }
        if (next_nr_wolf >= next_nr_sheep)
            continue;
        vector<int> next_targets(targets);
        next_targets.erase(next_targets.begin() + i);
        for (int i : g_edges[targets[i]]) {
            next_targets.push_back(i);
        }
        
        f(next_nr_sheep , next_nr_wolf, next_targets);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    g_info = &info;
    g_edges = vector<vector<int>>(info.size());
    for (auto edge : edges) {
        g_edges[edge[0]].push_back(edge[1]);
    }
    vector<int> targets;
    for (int i : g_edges[0]) {
        targets.push_back(i);
    }


    f(0, 0, {0});


    return answer;
}