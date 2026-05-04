#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    queue<pair<int,int>> q;
    vector<vector<int>> d(maps.size(),vector<int>(maps[0].size(),987654321));
    d[0][0] = 1;
    q.push({0,0});
    while(!q.empty()){
        auto coord = q.front();q.pop();
        int y = coord.first;
        int x = coord.second;
        if(y == maps.size()-1 && x == maps[0].size()-1){
            return d[y][x];
        }
        
        if(y+1 <maps.size() && maps[y+1][x]  && d[y+1][x] > d[y][x]+1){
            d[y+1][x] = d[y][x]+1;
            q.push({y+1,x});
        }

        if(y-1 >=0 && maps[y-1][x]  && d[y-1][x] > d[y][x]+1){
            d[y-1][x] = d[y][x]+1;
            q.push({y-1,x});
        }

        if(x+1 <maps[0].size() && maps[y][x+1]  && d[y][x+1] > d[y][x]+1){
            d[y][x+1] = d[y][x]+1;
            q.push({y,x+1});
        }

        if(x-1 >=0 && maps[y][x-1]  && d[y][x-1] > d[y][x]+1){
            d[y][x-1] = d[y][x]+1;
            q.push({y,x-1});
        }

        
        
    }
    

    return -1;
}