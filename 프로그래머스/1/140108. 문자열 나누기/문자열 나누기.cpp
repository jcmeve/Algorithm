#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;
    int i;
    for(i =0; i < s.size(); ){
        char x = s[i];
        int equal_cnt=0;
        int notequal_cnt=0;
        int j;
        for(j = i; j<s.size(); ++j){
            if(s[j] == x) equal_cnt++;
            else notequal_cnt++;
            if(equal_cnt == notequal_cnt){
                i = j+1;
                answer++;
                break;
            }
        }
        if(j == s.size())
            break;
    }
    if(i != s.size())
        answer++;
    return answer;
}