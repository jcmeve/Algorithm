#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> s;
    
    for(string str : phone_book)
        for(int i = 1; i < str.length();i++)
            s.insert(str.substr(0,i));
    
    for(string str : phone_book){
        if(s.find(str)!=s.end())
            return false;
    }
    return true;
}