#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> seoul) {
    auto iter = find(seoul.begin(), seoul.end(), "Kim");
    return "김서방은 "+to_string(iter - seoul.begin())+"에 있다";
}