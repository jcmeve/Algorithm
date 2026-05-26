#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<vector<int>> cache(land.size(),vector<int>(4,0));
    cache[0][0] = land[0][0];
    cache[0][1] = land[0][1];
    cache[0][2] = land[0][2];
    cache[0][3] = land[0][3];
    for(int i =1;i<land.size(); ++i){
        
        for(int j = 0; j < 4;++j){
            int temp = 0;
            for(int k =0; k < 4; ++k){
                if(j==k) continue;
                temp = max(temp, cache[i-1][k]+land[i][j]);
            }
            cache[i][j] = temp;
        }
    }
    
    for(int i =0; i < 4; ++i){
        answer = max(answer,cache[land.size()-1][i]);
    }
    return answer;
}