#include <string>
#include <vector>

using namespace std;
//가능한한 오른쪽에 0->1로 변경, 거기보다 오른쪽이면서 가능한 한 왼쪽에 1->0
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i = 0; i < numbers.size(); ++i){
        long long curr = numbers[i];
        int j;
        if(curr%2 == 0) {
            answer.push_back(curr+1);
            continue;
        }
        for(j =0; j < 8*sizeof(long long); ++j){
            if((1LL<<j & curr) == 0){
                curr |= 1LL<<j;
                break;
            }    
        }
        
        for(j-=1; j>=0; --j){
            if((1LL<<j & curr) != 0){
                curr -= (1LL<<j);
                break;
            }
        }
        answer.push_back(curr);
        
    }
    
    return answer;
}