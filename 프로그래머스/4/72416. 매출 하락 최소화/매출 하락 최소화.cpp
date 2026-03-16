#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> teamMembers; //팀 별 명단
vector<int>* g_sales;
vector<vector<int>> cache;
void f(int teamId){
    cache[teamId][0] = 0;
    cache[teamId][1] = (*g_sales)[teamId];
    if (teamMembers[teamId].empty()) return;
    
    bool check = false;
    int minPrice = 987654321;
    for(int i :teamMembers[teamId]){
        f(i);
        if(cache[i][0] < cache[i][1]){
            cache[teamId][0]+=cache[i][0];
            cache[teamId][1]+=cache[i][0];
            minPrice = min(minPrice, cache[i][1] -cache[i][0]);
        }else{
            cache[teamId][0]+=cache[i][1];
            cache[teamId][1]+=cache[i][1];
            check = true;
        }
    }
    
    if(!check){
        cache[teamId][0]+=minPrice;
    }
}


int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    g_sales = &sales;
    teamMembers = vector<vector<int>> (sales.size());
    cache = vector<vector<int>> (sales.size(), vector<int>(2,0));
    for(auto& link : links){
        teamMembers[link[0]-1].push_back(link[1]-1);
    }
    f(0);
    return min(cache[0][0],cache[0][1]);
    
}