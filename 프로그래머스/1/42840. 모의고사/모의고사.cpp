#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> jumsu = {0,0,0};

    for(int i = 0; i<answers.size();i++){
        if(answers[i] == (i%5)+1)
            jumsu[0]++;
    }
    
    //21232425
    int arr1[] = {2,1,2,3,2,4,2,5};
    for(int i = 0; i< answers.size();i++){
        if(arr1[i%8] == answers[i]){
            jumsu[1]++;
        }
    }
    
    int arr2[] = {3,3,1,1,2,2,4,4,5,5};
    for(int i = 0; i< answers.size();i++){
        if(arr2[i%10] == answers[i]){
            jumsu[2]++;
        }
    }
    
    int maxIdx =0;
    int maxJumsu = 0;
    for(int i = 0; i< jumsu.size();i++){
        if(maxJumsu<jumsu[i])
            maxJumsu = jumsu[i];
    }
    vector<int> answer;
    for(int i = 0; i< jumsu.size();i++){
        if(jumsu[i] == maxJumsu)
            answer.push_back(i+1);
    }
    
    
    
    
    return answer;
}