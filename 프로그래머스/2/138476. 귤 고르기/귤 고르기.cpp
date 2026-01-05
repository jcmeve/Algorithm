#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> m;
    for (int i : tangerine) {
        m[i]++;
    }
    vector<int> nr;
    nr.reserve(m.size());
    for (auto& pair : m) {
        nr.push_back(pair.second);
    }
    sort(nr.begin(), nr.end(), greater<int>());
    int idx = 0;
    while (k > 0) {
        k -= nr[idx++];
        ++answer;
    }


    return answer;
}