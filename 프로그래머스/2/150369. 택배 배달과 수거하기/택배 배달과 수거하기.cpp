#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int d_idx = n - 1;
    int p_idx = n - 1;
    
    while (d_idx >= 0 || p_idx >= 0) {
        while (d_idx >= 0 && deliveries[d_idx] == 0) d_idx--;
        while (p_idx >= 0 && pickups[p_idx] == 0) p_idx--;

        if (d_idx < 0 && p_idx < 0) break;

        int far = (d_idx > p_idx) ? d_idx : p_idx;
        answer += (long long)(far + 1) * 2;

        int d_cap = cap;
        while (d_idx >= 0 && d_cap > 0) {
            if (deliveries[d_idx] > d_cap) {
                deliveries[d_idx] -= d_cap;
                d_cap = 0;
            } else {
                d_cap -= deliveries[d_idx];
                deliveries[d_idx] = 0;
                d_idx--;
            }
        }

        int p_cap = cap;
        while (p_idx >= 0 && p_cap > 0) {
            if (pickups[p_idx] > p_cap) {
                pickups[p_idx] -= p_cap;
                p_cap = 0;
            } else {
                p_cap -= pickups[p_idx];
                pickups[p_idx] = 0;
                p_idx--;
            }
        }
    }

    return answer;
}