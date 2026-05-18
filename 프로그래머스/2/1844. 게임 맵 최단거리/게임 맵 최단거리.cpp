#include<vector>
#include<queue>
using namespace std;

int dy[]{0,0,-1,1};
int dx[]{-1,1,0,0};

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
        
        for(int i =0; i < 4; ++i){
            int newY = y+dy[i];
            int newX = x+dx[i];
            if(newY >=0 && newX >=0 && newX <maps[0].size() && newY <maps.size() && maps[newY][newX]  && d[newY][newX] > d[y][x]+1){
                d[newY][newX] = d[y][x]+1;
                q.push({newY,newX});
            }
            
        }
\
        
        
    }
    

    return -1;
}