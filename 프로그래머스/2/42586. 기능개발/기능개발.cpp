#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer = {0};

    
    int remain = (100-progresses[0]);
    int largest = (remain+speeds[0]-1)/speeds[0];
    
    for(int i = 0; i < progresses.size(); ++i){
        int remain = (100-progresses[i]);
        int t = (remain+speeds[i]-1)/speeds[i];
        if(largest<t){
            answer.push_back(0);
            largest = t;
        }
        answer[answer.size()-1]++;
    }
    
    return answer;
}