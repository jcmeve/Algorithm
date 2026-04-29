#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;


int solution(string word) {
    int answer = 0;
    unordered_map<char, int> m;
    m['A']=0;
    m['E']=1;
    m['I']=2;
    m['O']=3;
    m['U']=4;
    
    for(int i =0; i < word.size(); ++i){
        int acc = 0;
        for(int j = 0; j < 5-i; ++j){
            acc += pow(5,j);
        }
        answer+=acc*m[word[i]]+1;
        
    }
    
    
    
    return answer;
}