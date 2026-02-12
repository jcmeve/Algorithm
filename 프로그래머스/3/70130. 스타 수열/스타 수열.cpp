#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Status {
    int lastIdx = -1;
    int count = 0;
};

int solution(vector<int> a) {
    int n = a.size();
    if (n < 2) return 0;

    unordered_map<int, Status> m;
    for (int i = 0; i < n; ++i) {
        int curr = a[i];
        if (m[curr].lastIdx >= i) continue;
        if (i - 1 >= 0 && m[curr].lastIdx < i - 1 && a[i - 1] != curr) {
            m[curr].lastIdx = i; 
            m[curr].count++;
        }
        else if (i + 1 < n && a[i + 1] != curr) {
            m[curr].lastIdx = i + 1; 
            m[curr].count++;
        }
    }

    int answer = 0;
    for (auto const& [val, status] : m) {
        answer = max(answer, status.count);
    }

    return answer * 2;
}