#include <string>
#include <vector>
using namespace std;
int g_n;
int answer = 0;

void f(const vector<vector<bool>>& canPlace, int currX){
    if(currX == g_n){
        ++answer;
        return;
    }
    
    for(int y=0;y<g_n;++y){
        if(canPlace[y][currX]){
            auto temp = canPlace;
            for(int i = 0; i < g_n;++i){
                temp[y][i] = false;
                temp[i][currX] = false;
            }
            for(int i=-g_n;i<g_n;++i){
                if(y+i>=0 &&  y+i<g_n && currX+i>=0 && currX+i<g_n)
                    temp[y+i][currX+i] = false;
            }
            
            for(int i=-g_n;i<g_n;++i){
                if(y+i>=0 &&  y+i<g_n && currX-i>=0 && currX-i<g_n)
                    temp[y+i][currX-i] = false;
            }
            
            
            f(temp, currX+1);
            
        }
    }
    
}

int solution(int n) {
    g_n = n;
    
    vector<vector<bool>> v(n,vector<bool>(n,true));
    f(v, 0);
    
    return answer;
}