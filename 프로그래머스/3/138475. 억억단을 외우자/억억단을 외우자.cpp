#include <string>
#include <vector>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer(starts.size());
    vector<int> cache(e+1);
    for(int i = 1; i <= e; ++i){
        for(int j = 1; j*i<=e; ++j){
            cache[i*j]++;
        }
    }
    
    vector<int> max_vals(e+1);
    int M = -1;
    int v = -1;
    for(int i = e; i>0;--i){
        if(cache[i]>=M){
            M = cache[i];
            v = i;
        }
        max_vals[i] = v;
    }
    
    for(int i = 0; i < starts.size(); ++i){
        answer[i] = max_vals[starts[i]];
    }
    
    return answer;
}