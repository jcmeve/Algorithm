#include <string>
#include <vector>
using namespace std;

int solution(vector<string> board) {
    
    //OX nr
    int nrO =0;
    int nrX =0;
    for(const string& s : board){
        for(int i =0; i < 3; ++i){
            if(s[i] == 'O') ++nrO;
            if(s[i] == 'X') ++nrX;
        }
    }
    
    if (nrO!=nrX&&nrO!=nrX+1) return 0;
    
    bool winO = false;
    bool winX = false;
    //end
    for(int y=0;y<3;++y){
        int nrO = 0;
        int nrX = 0;
        for(int x =0;x<3;++x){
            if(board[y][x] == 'O') ++nrO;
            if(board[y][x] == 'X') ++nrX;
        }
        if(nrO == 3) winO = true;
        if(nrX == 3) winX = true;
    }
    for(int x =0;x<3;++x){
        int nrO = 0;
        int nrX = 0;
        for(int y=0;y<3;++y){
            if(board[y][x] == 'O') ++nrO;
            if(board[y][x] == 'X') ++nrX;
        }
        if(nrO == 3) winO = true;
        if(nrX == 3) winX = true;
    }
    if((board[0][0] == 'O') &&board[0][0] == board[1][1] && board[1][1] == board[2][2]) winO = true;
    if((board[0][0] == 'X') &&board[0][0] == board[1][1] && board[1][1] == board[2][2]) winX = true;
    if((board[2][0] == 'O') &&board[2][0] == board[1][1] && board[1][1] == board[0][2]) winO = true;
    if((board[2][0] == 'X') &&board[2][0] == board[1][1] && board[1][1] == board[0][2]) winX = true;
    
    if(winX && winO) return 0;
    if(winO && nrO!=nrX+1) return 0;
    if(winX && nrO!=nrX) return 0;
    
    return 1;
}