#include <string>
#include <vector>
#include<climits>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long l = 0;
    long long r = LLONG_MAX/100;
    for (;;) {
        long long t = (r+l)/2;

        long long s = 0;
        for (int i : times) {
            s += t / i;
        }
        if (s >= n) {
            r = t;
            if (answer != t) {
                answer = t;
                r = t;
            }
            else {
                return answer;
            }
        }
        else if (s < n) {
            l = t + 1;
        }


    }
    return answer;
}