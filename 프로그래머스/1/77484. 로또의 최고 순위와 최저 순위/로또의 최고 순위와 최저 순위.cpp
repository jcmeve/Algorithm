#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int nr_zero=0;
    int nr_hit = 0;
    int nr_miss = 0;
    for(int i = 0; i < lottos.size(); ++i){
        if(lottos[i] == 0){
            ++nr_zero;
        }else if(find(win_nums.begin(),win_nums.end(),lottos[i])!=win_nums.end()){
            nr_hit++;
        }else{
            nr_miss++;
        }
    }
    return {min(max(1,7-nr_hit-nr_zero),6),min(7-nr_hit,6)};
}