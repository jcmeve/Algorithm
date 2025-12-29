#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string arr[] = { "aya", "ye", "woo", "ma" };

    for (int i = 0; i < babbling.size(); ++i) {
        int j = 0;
        int last_word = -1;
        for (; j < babbling[i].size();) {
            for (int k = 0; k < 4; ++k) {
                int ret = babbling[i].find(arr[k], j);
                if (ret == j&&k != last_word) {
                    j += arr[k].size();
                    last_word = k;
                    goto A;
                }
            }
            break;
        A:;


        }
        if (j == babbling[i].size()) {
            ++answer;
        }
    }

    return answer;
}