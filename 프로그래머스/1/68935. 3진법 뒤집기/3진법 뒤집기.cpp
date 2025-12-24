#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n) {

    string s;
    
    for(;n>0; n/=3){
        s+=to_string(n%3);
    }
    int i = 0;
    while(s[i] == '0')++i;
    
    int answer = 0;
    for(; i <s.size(); ++i){
        answer*=3;
        answer+= s[i]-'0';
    }
    
    
    return answer;
}