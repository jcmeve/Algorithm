#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    int aIdx=0,bIdx=0;
    for(; aIdx < A.size() && bIdx<A.size(); ++bIdx){
        if(B[bIdx]>A[aIdx]){
            ++answer;
        }else{
            bIdx--;
        }
        ++aIdx;
    }
     
    return answer;
    
}