#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> m;
    for(int i = 0; i < 26; ++i) m[string(1, 'A' + i)] = i + 1;
    int nextIdx = 27;
    
    for(int l =0; l < msg.size();){
        int length = 1;
        while(l + length <= msg.size() && m.find(msg.substr(l, length)) != m.end()) {
            ++length;
        }
        --length;
        answer.push_back(m[msg.substr(l,length)]);
        if (l + length < msg.size()) {
            m[msg.substr(l, length + 1)] = nextIdx++;
        }
        l +=length;
    }
    
    return answer;
}