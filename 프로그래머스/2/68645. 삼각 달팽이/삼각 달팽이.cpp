#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    
    vector<int> answer(n*(n+1)/2,0);
    int x =0 ,y =-1;
    int length = n;
    int N = 1;
    for(;true;){
        //down
        for(int j = 0;j<length;j++){
            y++;
            answer[y*(y+1)/2+x] = N++;
        }
        length--;
        if(length == 0)
            break;
        //right
        for(int j = 0;j <length;j++){
            x++;
            answer[y*(y+1)/2+x] = N++;
        }
        length--;
        if(length == 0)
            break;
        for(int j = 0;j <length;j++){
            x--;
            y--;
            answer[y*(y+1)/2+x] = N++;
        }
        length--;
        if(length == 0)
            break;
    }
    return answer;
}