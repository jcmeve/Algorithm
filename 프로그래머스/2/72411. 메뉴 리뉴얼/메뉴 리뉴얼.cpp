#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;
vector<string> answer;
void f(const string& order, int nr, vector<bool> visited, int lastIdx){
   if(nr == 0){
        string s;
        for(int i =0; i < visited.size(); ++i){
            if(visited[i]){
                s += order[i];
            }
        }
        sort(s.begin(),s.end());
        m[s]++;
       return;
    }
    
    for(int i = lastIdx; i < order.size(); ++i){
        if(visited[i] == false){
            vector<bool> temp(visited.begin(),visited.end());
            temp[i] = true;
            f(order, nr-1, temp, i+1);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    for(string& order : orders){
        for(int nr : course){
            f(order,nr,vector<bool>(order.size(), false), 0);           
        }  
    }
    map<int, int> counts;
    map<int, vector<string>> currAnswer;
    for(auto& pair : m){
        if(pair.second >1){
            int length = pair.first.size(); 
            if(counts.find(length) != counts.end()){
                if(counts[length] < pair.second){
                    counts[length] = pair.second;
                    currAnswer[length].clear();
                    currAnswer[length].push_back(pair.first);
                }else if(counts[length] == pair.second){
                    currAnswer[length].push_back(pair.first);
                }
            }else{
                counts[length] = pair.second;
                currAnswer[length].push_back(pair.first);
            }
        }
    }
    for(auto& pair : currAnswer){
        for(string& s : pair.second){
            answer.push_back(s);
        }
    }
    sort(answer.begin(),answer.end());
    
    return answer;
}