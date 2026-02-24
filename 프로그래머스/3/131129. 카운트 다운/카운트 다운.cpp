#include <string>
#include <vector>

using namespace std;
vector<int> solution(int target) {
    vector<pair<int,int>> cache{100001,{987654321,-1}};

    for(int i = 1; i <= target;++i){
        if(i <= 20) {cache[i] = {1,1}; continue;}
        if(i == 50) {cache[i] = {1,1}; continue;}
        if(i%2 == 0 && i <= 40){cache[i] = {1,0};continue;}
        if(i%3 == 0 && i <= 60){cache[i] = {1,0};continue;}
        pair<int,int> best{987654321,-1};
        for(int j = 1;j<=60 && j<i;++j){
            pair<int,int> temp;
            temp.first = cache[i-j].first+cache[j].first;
            temp.second = cache[i-j].second+cache[j].second;
            
            if(temp.first<best.first) best = temp;
            else if(temp.first == best.first && best.second<temp.second) best = temp;
            
        }
        cache[i] = best;
    }
    
    return {cache[target].first,cache[target].second};
}