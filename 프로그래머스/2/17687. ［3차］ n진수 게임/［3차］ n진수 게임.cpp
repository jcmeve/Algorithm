#include <string>
#include <vector>
#include <algorithm>
using namespace std;


string convert = "0123456789ABCDEF";
string solution(int n, int t, int m, int p) {
    string answer = "";
    int curr = 0;
    int idx = 0;
    for (int i = 0; i < t;) {
        string converted = "";
        int temp = curr;
        if (temp == 0) converted = "0";
        else {
            while (temp > 0) {
                converted += convert[temp % n];
                temp /= n;
            }
            reverse(converted.begin(), converted.end());
        }

        for (int j = 0; j < converted.length(); ++j) {
            if (idx % m == p - 1) {
                answer += converted[j];
                i++;
                if (i == t) break;
            }
            idx++;
        }
        curr++;
    }

    return answer;
}
