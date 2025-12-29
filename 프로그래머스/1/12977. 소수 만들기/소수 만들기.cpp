#include <vector>
#include <iostream>
using namespace std;

int cache[3000]={0,};
int solution(vector<int> nums) {
    int answer = 0;

    for(int i = 2; i < 3000; ++i){
        for(int j = 2; j *i<3000; ++j){
            cache[j*i] = 1;
        }
    }
    
    for(int i = 0; i < nums.size()-2;++i){
        for(int j = i+1; j < nums.size()-1;++j){
            for(int k = j+1; k < nums.size();++k){
                if(cache[nums[i]+nums[j]+nums[k]] == 0)
                    ++answer;
            }
        }
    }
    

    return answer;
}