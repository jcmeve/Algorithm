#include <string>
#include <vector>
#include <memory.h>

using namespace std;
int cache[101];
int idx_cache = 0;
int solution(int n, vector<vector<int>> wires) {
    int answer = 21341234;
    for(int i = 0; i < wires.size(); ++i){
        memset(cache, 0, sizeof(int)*101);
        cache[wires[i][0]] = 1;
        cache[wires[i][1]] = 2;
        idx_cache = 2;
        for(int j =0; j < wires.size(); ++j){
            if( j == i)
                continue;
            if(cache[wires[j][0]]*cache[wires[j][1]] != 0 && cache[wires[j][0]] != cache[wires[j][1]]){
                int s = cache[wires[j][1]];
                int d = cache[wires[j][0]];
                
            
                for(int k = 0; k < 101; ++k){
                    if(cache[k] == s)
                        cache[k] = d;
                }
            }
            else if(cache[wires[j][0]] == 0  && cache[wires[j][0]] == cache[wires[j][1]] ){
                ++idx_cache;
                cache[wires[j][0]] = idx_cache;
                cache[wires[j][1]] = idx_cache;
            }else if(cache[wires[j][0]]*cache[wires[j][1]] == 0){
                if(cache[wires[j][0]] == 0){
                    cache[wires[j][0]] = cache[wires[j][1]];
                }else{
                    cache[wires[j][1]] = cache[wires[j][0]];
                }
            }
            
            
        }
        int tree_size[101];
        memset(tree_size, 0, sizeof(int)*101);
        for(int j = 0; j < 101; ++j){
            tree_size[cache[j]]++;
        }
        int s1=0,s2 = 0;
        for(int j = 1; j < 101; ++j){
            if(tree_size[j]){
                if(s1 == 0)
                    s1 = tree_size[j];
                else{
                    s2 = tree_size[j];
                    break;
                }
            }
        }
        answer = min(answer, abs(s1-s2));
    }
    return answer;
}