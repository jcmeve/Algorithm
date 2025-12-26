#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = 0;
    string dic[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
    size_t sIdx = 0;
    for (; sIdx < s.size();) {
        for (int i = 0; i < 10; ++i) {
            if (s[sIdx] == '0'+i) {
                ++sIdx;
                answer *= 10;
                answer += i;
                goto A;
            }
        }
        for (int i = 0; i < 10; ++i) {
            auto iter = s.find(dic[i], sIdx);
            if (iter == sIdx) {
                answer *= 10;
                answer += i;
                sIdx += dic[i].size();
                goto A;
            }
        }

    A:;

    }
    return answer;
}