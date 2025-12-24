#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    sort(number.begin(), number.end());
    
    for(int i =0; i < number.size()-2; ++i){
        for(int j =i+1; j<number.size()-1; ++j){
            int sum = number[i]+number[j];
            for(int k = j+1; k<number.size(); ++k){
                if(number[k]>-sum){
                    break;
                }
                if(number[k] == -sum){
                    ++answer;
                    continue;
                }
            }
            
        }
    }
    
    return answer;
}