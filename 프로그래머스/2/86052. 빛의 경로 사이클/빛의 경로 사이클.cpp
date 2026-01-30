#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int up = 0;
int right = 1;
int down = 2;
int left = 3;
int xDir[] = {0,1,0,-1};
int yDir[] = {-1,0,1,0};
vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    int height = grid.size();
    int width = grid[0].size();
    vector<vector<int>> g(height*width,{0,0,0,0});
    int id = 0;
    for(int y =0;y<height;++y){
        for(int x = 0; x < width; ++x){
            for(int dir = 0; dir<4;++dir){
                if(g[y*width+x][dir] == 0){    
                    int tempY = y;
                    int tempX = x;
                    int tempDir = dir;
                    ++id;
                    int length = 0;
                    for(;g[tempY*width+tempX][tempDir] == 0;){
                        ++length;
                        g[tempY*width+tempX][tempDir] = id;
                        tempY = (tempY + yDir[tempDir] + height) % height;
                        tempX = (tempX + xDir[tempDir] + width) % width;
                        switch(grid[tempY][tempX]){
                            case 'S': 
                                break;
                            case 'L':
                                tempDir+=3;
                                break;
                            case 'R':
                                tempDir+=1;
                                break;
                        }
                        tempDir%=4;
                    }
                    answer.push_back(length);
                }
            }
        }
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}