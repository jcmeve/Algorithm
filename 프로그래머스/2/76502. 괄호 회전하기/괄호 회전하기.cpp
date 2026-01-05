#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    for(int i =0; i < s.size(); ++i){
        string str = s.substr(i)+s.substr(0,i);
        stack<char> ss;
        for(int j = 0; j < str.size(); ++j){
            if((str[j] == ')' && (ss.empty() || ss.top() != '('))||
              (str[j] == '}' && (ss.empty() ||  ss.top() != '{'))||
              (str[j] == ']' && (ss.empty() ||  ss.top() != '['))){
                goto _out;
            }
            if((str[j] == ')' && ss.top() == '(')||
              (str[j] == '}' && ss.top() == '{')||
              (str[j] == ']' && ss.top() == '[')){
                ss.pop();
                continue;
            }
            ss.push(str[j]);
            
        }
        if(ss.empty()){
            ++answer;
        }
        _out:;
        
        
    }
    return answer;
}