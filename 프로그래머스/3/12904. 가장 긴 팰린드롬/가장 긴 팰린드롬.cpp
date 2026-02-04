#include <string>
using namespace std;
int solution(string s)
{
    int answer=0;
    for(int i =0; i < s.size(); ++i){
        int cnt = 1;
        for(int j = 1; j < s.size(); ++j){
            if(i-j<0 || i+j >= s.size() || s[i-j] != s[i+j]) break;
            cnt+=2;
        }
        answer = answer>cnt?answer:cnt;
    }

    for(int i =0; i < s.size(); ++i){
        if(i+1 < s.size() && s[i] == s[i+1]){
            int cnt = 2;
            for(int j = 1; j < s.size(); ++j){
                if(i-j<0 || i+1+j >= s.size() || s[i-j] != s[i+1+j]) break;
                cnt+=2;
            }
            answer = answer>cnt?answer:cnt;
        }
    }
    
    return answer;
}