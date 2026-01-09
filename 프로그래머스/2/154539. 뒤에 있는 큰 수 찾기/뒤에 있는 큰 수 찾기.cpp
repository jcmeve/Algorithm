#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> s;
    answer.push_back(-1);
    s.push(numbers[numbers.size()-1]);
    for(int i = numbers.size()-2; i>=0; --i){
        while(!s.empty()&& s.top()<=numbers[i]) s.pop();
        if(s.empty()){
            answer.push_back(-1);
        }else{
            answer.push_back(s.top());
        }
            s.push(numbers[i]);    
        
    }
    return {answer.rbegin(),answer.rend()};
}