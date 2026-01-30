#include <string>
#include <vector>
#include <algorithm>
using namespace std;



vector<int> solution(vector<string> operations) {
    vector<int> answer = { 0,0 };

    vector<int> l,g;



    for (const string& s : operations) {

        if (s[0] == 'I') {
            int v = stoi(string(s.begin() + 2, s.end()));
            l.push_back(v);
            g.push_back(v);
        }
        else
        {
            if (l.empty())
                continue;
            if (s[2] == '1') {
                for (int i = l.size()-1; i >=0; --i) {
                    if (l[i] == g[0])
                        l.erase(l.begin() + i);
                }
                g.erase(g.begin());

            }
            else {
                for (int i = g.size() - 1; i >= 0; --i) {
                    if (g[i] == l[0])
                        g.erase(g.begin() + i);
                }
                l.erase(l.begin());

            }
        }
        make_heap(l.begin(), l.end(), greater<int>());
        make_heap(g.begin(), g.end());

    }
    
    if (!g.empty()) {
        answer[0] = g.front();
        answer[1] = l.front();
    }

    return answer;
}
