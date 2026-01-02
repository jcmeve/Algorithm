#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2,0);
    for(int x = brown-2; x >=3; --x){
        if((brown - 2*x)%2)\
            continue;
        
        int y = (brown - 2*x)/2+2;
        
        
        if((x-2)*(y-2) == yellow){
            answer[0] = x;
            answer[1] = y;
            return answer;
        }
    }
    return answer;
}