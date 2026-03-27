#include <string>
#include <vector>
#include <set>
using namespace std;
set<vector<bool>> cache;
int answer = 0;

bool check(const string& id, const string& banned_id){
    if(id.size() != banned_id.size()) return false;
    for(int i =0; i<id.size(); ++i){
        if(banned_id[i] == '*') continue;
        if(id[i]!=banned_id[i]) return false;
    }
    return true;
}

void f(vector<string>& user_id, vector<string>& banned_id, vector<bool> visited, int bannedIdx){
    if(bannedIdx == banned_id.size()){
        if(cache.find(visited) != cache.end()){
            return;
        }
        cache.insert(visited);
        ++answer;
        return;
    }
    for(int i = 0; i < user_id.size(); ++i){
        if(visited[i] == true) continue;
        if(check(user_id[i], banned_id[bannedIdx])){
            vector<bool> temp(visited.begin(),visited.end());
            temp[i] = true;
            f(user_id, banned_id, temp, bannedIdx+1);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    f(user_id, banned_id, vector<bool>(user_id.size(), false), 0);
    return answer;
}