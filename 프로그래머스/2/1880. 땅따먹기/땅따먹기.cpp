#include <iostream>
#include <vector>
using namespace std;


int solution(vector<vector<int> > land)
{
    vector<vector<int>> dp{land.size(),vector<int>{4,0}};
    for(int i =0;i<4;++i)
        dp[0][i] = land[0][i];
    
    for(int i =1;i<land.size(); ++i){
        for(int j = 0; j<4; ++j){
            int M = -1;
            for(int k = 1; k<4;++k){
                M = max(M,dp[i-1][((j+k)%4)]);
            }
            dp[i][j] = land[i][j] + M;
        }
    }
    int answer = -1;
    for(int i = 0; i < 4; ++i){
        answer = max(answer, dp[land.size()-1][i]);
    }
    return answer;
}