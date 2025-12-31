#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> stash;
    
    for(int i : ingredient){
        stash.push_back(i);
        int idx = stash.size()-1;
        for(;idx>=3;){
            if(stash[idx] == 1 && stash[idx-1] ==3 &&stash[idx-2] == 2&&stash[idx-3] == 1){
                ++answer;
                stash.erase(stash.end() - 4, stash.end());
                idx-=4;
            }else{
                break;
            }
        }
    }
    return answer;
}