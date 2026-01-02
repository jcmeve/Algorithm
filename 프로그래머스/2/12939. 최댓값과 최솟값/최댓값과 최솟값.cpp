#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    istringstream iss(s);
    int i;
    int m = 987654321,M= -987654321;
    while(iss>>i){
        m = min(m,i);
        M = max(M,i);
    }
    answer+=(std::to_string(m));
    answer+=' ';
    answer+=(std::to_string(M));
    return answer;
}