#include <string>
#include <vector>

using namespace std;
int cache['z'-'a'+1];
vector<int> solution(string s) {
    vector<int> answer;
    for(int i =0; i < 'z'-'a'+1;++i ){
        cache[i] = -1;
    }
    for(int i = 0; i < s.size(); ++i){
        if(cache[s[i]-'a'] == -1)
            answer.push_back(-1);
        else
            answer.push_back(i - cache[s[i]-'a']);
        cache[s[i]-'a'] = i;
    }
    
    return answer;
}