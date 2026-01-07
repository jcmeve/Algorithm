#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    answer.resize(right-left+1);
    for(long long i = left; i<=right; ++i){
        long long x = i%n;
        long long y = i/n;
        answer[i-left] = (x<y)?y+1:x+1; 
    }
        
    return answer;
}