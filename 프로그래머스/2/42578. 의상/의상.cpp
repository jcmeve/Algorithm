#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,char> map;
    for(vector<string> vec : clothes){
        map[vec[1]]++;
        
    }
    for(auto element : map){
        answer *= (element.second+1);
    }
    
    return answer-1;
}