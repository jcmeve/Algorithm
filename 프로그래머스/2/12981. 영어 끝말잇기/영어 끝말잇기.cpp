#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string,bool> m;
    char last = words[0][0];
    for(int i =0; i < words.size(); ++i){
        if( m.find(words[i])!=m.end() || (last!=words[i][0])){
            return {i%n+1,i/n+1};
        }
        last = words[i][words[i].size()-1];
        m[words[i]] = true;
    }
    return {0,0};
}