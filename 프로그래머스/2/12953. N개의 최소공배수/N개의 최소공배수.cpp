#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    for(int i = 1;;++i){
        bool flag = false;
        for(int j : arr){
            if(i%j != 0){
                flag = true;
                break;
            }          
        }
        if(flag == false)return i;
        
    }
    
    return answer;
}