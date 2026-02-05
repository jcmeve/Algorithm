#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    vector<int> leftMin(a.size());
    vector<int> rightMin(a.size());
    int currentLeftMin = 1000000001;
    for(int i = 0; i< a.size();i++){
        leftMin[i] = currentLeftMin;
        if(a[i]<currentLeftMin){
            currentLeftMin = a[i];
        }
    }
    int currentRightMin = 1000000001;
    for(int i = a.size()-1;i>=0;i--){
        rightMin[i] = currentRightMin;
        if(a[i]<currentRightMin){
            currentRightMin = a[i];
        }
    }
    for(int i = 0; i< a.size();i++){
        if(!(leftMin[i]<a[i] && rightMin[i]<a[i]))
        answer ++;
    }
    

    return answer;
}