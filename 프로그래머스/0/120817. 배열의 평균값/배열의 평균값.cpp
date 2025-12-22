#include <vector>
using namespace std;
double solution(vector<int> numbers) {
    double answer = 0;
    for(const int& v : numbers)
        answer += v;
    return answer/numbers.size();
}