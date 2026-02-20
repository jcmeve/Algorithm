#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    vector<long long> a2;
    vector<vector<int>>g(edges.size() + 1);
    vector<int> edgeCount(edges.size() + 1, 0);
    long long checkSum = 0;
    for (int i = 0; i < edges.size(); ++i) {
        g[edges[i][0]].push_back(edges[i][1]);
        g[edges[i][1]].push_back(edges[i][0]);
        edgeCount[edges[i][0]]++;
        edgeCount[edges[i][1]]++;
    }
    for (int i : a) {
        checkSum += i;
        a2.push_back(i);
    }
    if (checkSum != 0)
        return -1;
    stack<int> s;
    for (int i = 0; i < g.size(); ++i) {
        if (g[i].size() == 1) {
            s.push(i);
        }
    }

    while (!s.empty()) {
        int currNode = s.top();
        s.pop();
        long long currWeight = a2[currNode];
        if (edgeCount[currNode] == 0) {
            if (a2[currNode] == 0) break;
            return -1;
        }
        if (edgeCount[currNode] != 1) {
            continue;
        }
        for (int i = 0; i < g[currNode].size(); ++i) {
            int nextNode = g[currNode][i];
            if (edgeCount[nextNode] >0) {
                edgeCount[nextNode]--;
                edgeCount[currNode]--;
                a2[nextNode] += currWeight;
                a2[currNode] -= currWeight;
                answer += abs(currWeight);
                s.push(nextNode);
                break;
            }
        }
        
    }



    return answer;
}

