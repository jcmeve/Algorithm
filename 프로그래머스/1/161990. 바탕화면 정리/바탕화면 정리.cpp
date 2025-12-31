#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    
    int lux=100,luy=100,rdx=-1,rdy=-1;
    for(int y = 0; y < wallpaper.size(); y++){
        for(int x = 0; x < wallpaper[0].size(); x++){
            if(wallpaper[y][x] == '#'){
                luy = luy>y?y:luy;
                lux = lux>x?x:lux;
                rdy = rdy<y?y:rdy;
                rdx = rdx<x?x:rdx;
            }
        }
    }
    vector<int> answer = {luy,lux,rdy+1,rdx+1};
    return answer;
}