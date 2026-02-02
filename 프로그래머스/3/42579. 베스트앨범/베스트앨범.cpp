#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

bool compSIPair(pair<string,int> p1,pair<string,int> p2 ){return p1.second>p2.second; }
bool compIIPair(pair<int,int> p1, pair<int,int> p2){
    if(p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second>p2.second;
    
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string,int> rankMap;
    for(int i = 0; i<genres.size();i++)
        rankMap[genres[i]] += plays[i];
    vector<pair<string,int> > rankVec(rankMap.begin(),rankMap.end());
    sort(rankVec.begin(),rankVec.end(),compSIPair);
    
    unordered_map<string,vector<pair<int,int>>> table;
    for(int i = 0; i< genres.size();i++){
        table[genres[i]].push_back(make_pair(i,plays[i]));
    }
    
    for(auto& vec : table){
        sort(vec.second.begin(),vec.second.end(),compIIPair);
    } 

    
    for(auto& rank : rankVec){   //rank.first is genre name
        for(int i = 0 ; i < 2&&i<table[rank.first].size();i++){
            answer.push_back(table[rank.first][i].first);
        }
    }
    
    
    return answer;
}