#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int cacheX[10];
int cacheY[10];
string solution(string X, string Y) {
    string answer = "";
    for(int i =0 ; i < X.size();++i){

        cacheX[X[i]-'0']++;
    }
    for(int i =0 ; i < Y.size();++i){
        cacheY[Y[i]-'0']++;
    }
    for(int i = 9; i >= 0; --i){
        if(cacheX[i]>0 && cacheY[i]>0){
            if(answer == "0")
                break;
            answer+=(i+'0');
            cacheX[i]--;
            cacheY[i]--;
            ++i;
        }
    }
    if(answer.size() == 0) answer = "-1";
    return answer;
}