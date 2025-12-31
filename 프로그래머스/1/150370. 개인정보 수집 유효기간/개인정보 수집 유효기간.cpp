#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char, int> term;
    for (auto s : terms) {
        
        term[s[0]] = stoi(s.substr(2,s.size()-2));
    }
    
    int today_y = stoi(today.substr(0,4));
    int today_m = stoi(today.substr(5,2));
    int today_d = stoi(today.substr(8,2));

    int today_days = today_y*12*28+today_m*28+today_d;
    for(auto pair : term){//start day
        
    }
    
    for(int i =0 ;i<privacies.size(); ++i){
        string& s = privacies[i];
        char type = s[s.size()-1];

        int p_y = stoi(s.substr(0,4));
        int p_m = stoi(s.substr(5,2)) + term[type];
        int p_d = stoi(s.substr(8,2));
        int ex_days = p_y*12*28+p_m*28+p_d;
        if(today_days>=ex_days){
            answer.push_back(i+1);
        }
    }
    

    return answer;
}