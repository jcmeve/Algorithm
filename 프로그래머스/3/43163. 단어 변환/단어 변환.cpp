#include <string>
#include <vector>
#include <queue>
using namespace std;
int d[51];

bool canChange(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == b[i])
            continue;
        ++cnt;
        if (cnt == 2)
            return false;
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    bool flag = false;
    int i, b, t;
    for (i = 0; i < words.size(); ++i) {
        if (words[i] == begin) {
            flag = true;
            break;
        }
    }
    if (flag) {
        b = i;
    }
    else {
        words.push_back(begin);
        b = words.size() - 1;
    }

    flag = false;
    for (i = 0; i < words.size(); ++i) {
        if (words[i] == target) {
            flag = true;
            break;
        }
    }
    if (flag) {
        t = i;
    }
    else {
        return 0;
    }



    vector<vector<int>> g(words.size());

    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < words.size(); ++j) {
            if (i == j)
                continue;
            if (canChange(words[i], words[j])) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    queue<int> q;
    q.push(b);
    for (; !q.empty();) {
        int curr = q.front();
        q.pop();
        int dist = d[curr];
        for (i = 0; i < g[curr].size(); ++i) {
            if (d[g[curr][i]])
                continue;
            d[g[curr][i]] = dist + 1;
            q.push(g[curr][i]);
        }

    }


    return d[t];
}