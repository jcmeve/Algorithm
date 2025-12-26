#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int arr[201]={0,};
    for(int i = 0; i < numbers.size(); i++){
        for(int j = i+1; j < numbers.size();j++){
            arr[numbers[i]+numbers[j]] = 1;
        }
    }
    for(int i = 0; i< 200; i++)
        if(arr[i] == 1)
            answer.push_back(i);
    
    
    return answer;
}