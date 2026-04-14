#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 987654321;
    deque<int> dq;
    for (int i = 0; i < stones.size(); ++i) {
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        while (!dq.empty() && stones[dq.back()] <= stones[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);

        if (i >= k - 1) {
            answer = min(answer, stones[dq.front()]);
        }
    }
    return answer;
}