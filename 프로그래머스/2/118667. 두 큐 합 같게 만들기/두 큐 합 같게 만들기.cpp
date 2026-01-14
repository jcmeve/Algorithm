#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;



int solution(vector<int> queue1, vector<int> queue2) {
    unsigned long long answer = 0;
    unsigned long long acc1 = 0;
    unsigned long long acc2 = 0;
    for (int i : queue1) acc1 += i;
    for (int i : queue2) acc2 += i;
    if ((acc1 + acc2) % 2) return -1;

    vector<int> totalQueue(queue1);
    totalQueue.assign(queue2.begin(), queue2.end());
    sort(totalQueue.begin(), totalQueue.end(), greater<int>());
    
    
    queue<int> q1;
    for (int i : queue1) q1.push(i);
    queue<int> q2;
    for (int i : queue2) q2.push(i);

    int failCnt = 0;    
    for (; acc1 != acc2; ++answer) {
        if (acc1 > acc2) {
            acc1 -= q1.front();
            acc2 += q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else {
            acc2 -= q2.front();
            acc1 += q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        ++failCnt;
        if(failCnt>(queue1.size()+queue2.size())*2)
            return -1;
    }


    return answer;
}