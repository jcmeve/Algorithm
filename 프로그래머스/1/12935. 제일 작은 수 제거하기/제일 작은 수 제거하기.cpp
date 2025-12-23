#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    int minIdx;
    int minVal = 987654321;
    if(arr.size() == 1)
        return {-1};
    
    for(int i = 0; i < arr.size(); ++i){
        if(arr[i]<minVal){
            minIdx = i;
            minVal = arr[i];
        }
    }
    arr.erase(arr.begin()+minIdx,arr.begin()+minIdx+1);
    
    
    return arr;
}