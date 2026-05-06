#include <string>
#include <vector>
using namespace std;

vector<int>* g_info;
vector<vector<int>> g_edges;
int answer = 0;
void f(int nr_sheep,int nr_wolf, vector<int>& targets) {

    answer = max(answer, nr_sheep);

    for (int i = 0; i < targets.size(); ++i) {
        if(targets[i] == 0) continue;
        
        int next_nr_sheep = nr_sheep;
        int next_nr_wolf = nr_wolf;
        if ((*g_info)[i] == 0) {
            ++next_nr_sheep;
        }
        else {
            ++next_nr_wolf;
        }
        if (next_nr_wolf >= next_nr_sheep)
            continue;
        
        targets[i]=0;
        for (int j : g_edges[i]) {
            targets[j]=1;
        }
        
        f(next_nr_sheep , next_nr_wolf, targets);
        
        targets[i]=1;
        for (int j : g_edges[i]) {
            targets[j]=0;
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    g_info = &info;
    g_edges = vector<vector<int>>(info.size());
    for (auto edge : edges) {
        g_edges[edge[0]].push_back(edge[1]);
    }
    vector<int> targets(info.size(),0);
    targets[0] = 1;
    f(0, 0, targets);

    return answer;
}