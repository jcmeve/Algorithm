#include <string>
#include <vector>
using namespace std;
int cache['Z'-'A'+1];
vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(int i =0; i < keymap.size(); ++i){
        for(int j =0; j < keymap[i].size(); ++j){
            if(cache[keymap[i][j]-'A'] == 0 || cache[keymap[i][j]-'A']>j+1) {    
                cache[keymap[i][j]-'A']=j+1;
            }
        }
    }

    for(int i =0; i < targets.size(); ++i){
        int cnt=0;
        for(int j = 0; j < targets[i].size();++j){
            if(cache[targets[i][j]-'A'] == 0){
                answer.push_back(-1);
                goto for_out;
            }
            cnt+=cache[targets[i][j]-'A'];
        }
        answer.push_back(cnt);
        for_out:;
    }
    
    return answer;
}