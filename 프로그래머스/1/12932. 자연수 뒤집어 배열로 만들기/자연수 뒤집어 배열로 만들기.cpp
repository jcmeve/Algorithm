#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    for(;n>0;n/=10)
        answer.push_back(n%10);
    return answer;
}