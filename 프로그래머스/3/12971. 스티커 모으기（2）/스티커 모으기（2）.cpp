#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    if (sticker.size() == 1) return sticker[0];
    if (sticker.size() == 2) return max(sticker[0], sticker[1]);
    
    vector<int> dp0(sticker.size(),0);
    vector<int> dp1(sticker.size(),0);

    dp0[0] = sticker[0];
    dp0[1] = dp0[0];
    for(int i =2; i < sticker.size()-1; ++i){
        dp0[i] = max(dp0[i-2]+sticker[i], dp0[i-1]);
    }
    dp1[1] = sticker[1];
    for(int i = 2;i<sticker.size(); ++i){
        dp1[i] = max(dp1[i-2]+sticker[i], dp1[i-1]);
    }
    return max(dp0[sticker.size()-2],dp1[sticker.size()-1]);
}