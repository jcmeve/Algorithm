#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void f(int n,int s, int d){
    if(n == 1){
        answer.push_back({s,d});
        return;
    }
    f(n-1,s,6-s-d);
    answer.push_back({s,d});
    f(n-1,6-s-d,d);
}

vector<vector<int>> solution(int n) {
    
    f(n,1,3);
    return answer;
}