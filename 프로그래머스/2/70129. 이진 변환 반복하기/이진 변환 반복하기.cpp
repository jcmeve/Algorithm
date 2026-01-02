#include <string>
#include <vector>
#include <bitset>
using namespace std;

vector<int> solution(string s) {
    int turn = 0;
    int totalZero = 0;
    for (;s.size() != 1;) {

        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') ++cnt;
        }
        totalZero+=( s.size() - cnt);
        bitset<32> a = (cnt);
        s = a.to_string().substr(a.to_string().find('1'));
        ++turn;
    }
    return { turn,totalZero };
}