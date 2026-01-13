#include <string>
#include <vector>
#include <stack>
using namespace std;


int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    for (int i = 0; i < order.size(); ++i) {
        if (!s.empty() && (s.top() == order[answer])) {
            --i;
            s.pop();
            ++answer;
            continue;
        }
        if (i + 1 == order[answer]) {
            ++answer;
            continue;
        }
        if (i + 1 > order[answer]) {
            break;
        }
        s.push(i + 1);
    }
    while (!s.empty() && s.top() == order[answer]) {
        s.pop();
        ++answer;
    }


    return answer;
}