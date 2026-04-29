#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a1={1,2,3,4,5};
vector<int> a2={2,1,2,3,2,4,2,5};
vector<int> a3={3,3,1,1,2,2,4,4,5,5};
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> counts(3,0);
    vector<int> idxes(3,0);
    for(int i =0; i < answers.size(); ++i){
        if(answers[i] == a1[idxes[0]]) ++counts[0];
        if(answers[i] == a2[idxes[1]]) ++counts[1];
        if(answers[i] == a3[idxes[2]]) ++counts[2];
        ++idxes[0];
        ++idxes[1];
        ++idxes[2];
        idxes[0]%=a1.size();
        idxes[1]%=a2.size();
        idxes[2]%=a3.size();
    }
    int M = *max_element(counts.begin(),counts.end());
    for(int i =0; i < counts.size(); ++i){
        if(counts[i] == M)
            answer.push_back(i+1);
    }
    
    
    return answer;
}