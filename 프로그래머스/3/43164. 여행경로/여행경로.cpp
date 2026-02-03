#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int g_Cnt = 0;
vector<string> answer;

void f(map<string, vector<string>>& tickets, vector<string>& visited){
    if(!answer.empty()) return;
    if(g_Cnt == visited.size()-1){
        answer = visited;
        return;
    }
    string curr = visited[visited.size()-1];
    for(auto& dst : tickets[curr]){
        vector<string> tempVisited(visited.begin(),visited.end());
        tempVisited.push_back(dst);
        map<string, vector<string>> tempTickets(tickets.begin(),tickets.end());
        tempTickets[curr].erase(find( tempTickets[curr].begin(),tempTickets[curr].end(), dst));
        f(tempTickets, tempVisited);
    }
    
}
bool comp(const string& a, const string& b){
    return a<b;
}
vector<string> solution(vector<vector<string>> tickets) {
    map<string, vector<string>> g;
    for(auto& ticket : tickets){
        g[ticket[0]].push_back(ticket[1]);
    }
    for(auto& v : g){
        sort(v.second.begin(),v.second.end(),comp);
    }
    g_Cnt = tickets.size();
    vector<string> s{"ICN"};
    f(g,s);
    
    return answer;
}