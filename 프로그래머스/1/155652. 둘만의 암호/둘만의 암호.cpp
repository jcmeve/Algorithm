#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for(int i =0; i<s.size(); ++i){
        char idx = s[i]-'a';
        for(int j =0 ; j < index; ++j){
            idx++;
            idx%='z'-'a'+1;
            while(string::npos!= skip.find(idx+'a')) {
                ++idx;
                idx%='z'-'a'+1;
            }
            
        }
        answer+=idx+'a';
    }
    
    return answer;
}