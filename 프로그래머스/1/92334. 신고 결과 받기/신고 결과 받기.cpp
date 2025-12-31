#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    unordered_map<string, int> name_to_idx;
    for (int i = 0; i < id_list.size(); ++i) {
        name_to_idx[id_list[i]] = i;
    }

    vector<unordered_set<int>> reporters(name_to_idx.size());
    for (int i = 0; i < report.size(); ++i) {
        istringstream iss(report[i]);
        string reporter, target;
        iss >> reporter>> target;
        reporters[name_to_idx[target]].insert(name_to_idx[reporter]);
    }
    vector<int> answer(name_to_idx.size(),0);

    for (int i = 0; i < reporters.size(); ++i) {
        if (reporters[i].size() >= k) {
            for (int id : reporters[i]) {
                answer[id]++;
            }
        }
    }

    return answer;
}