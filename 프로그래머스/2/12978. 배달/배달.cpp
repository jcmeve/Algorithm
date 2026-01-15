#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<pair<int,int>>> g;
bool possible[51];
int MaximumRemain[51];
int answer = 0;
void f(vector<int> been, int vertex, int remain){
    if(remain<0)
        return;
    if(MaximumRemain[vertex]>remain)
        return;
    MaximumRemain[vertex] =remain;
    if(!possible[vertex]){
        possible[vertex]=true;
        ++answer;
    }
    been.push_back(vertex);
    for(auto pair : g[vertex]){
        if(find(been.begin(),been.end(),pair.first) == been.end())
            f(been, pair.first,remain-pair.second);
    }
}


int solution(int N, vector<vector<int> > road, int K) {
    g = vector<vector<pair<int,int>>>(N+1);// a->[b,c];
    for(auto v : road){
        g[v[0]].push_back({v[1],v[2]});
        g[v[1]].push_back({v[0],v[2]});        
    }
    

    f({},1,K);

    return answer;
}