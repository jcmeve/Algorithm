#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    map<int,int> m;
    for(int i =2; i < s.size()-1; ++i){
        if(!(s[i]>='0' && s[i]<='9')) continue;
        int a=0;
        while(s[i]>='0' && s[i]<='9'){
            a*=10;
            a+=s[i]-'0';
            ++i;
        }
        m[a]++;
    }
    vector<int> answer(m.size(),0);
    
    for(auto pair : m){
        answer[m.size()-pair.second] = pair.first;
    } 
    
    
    return answer;
}