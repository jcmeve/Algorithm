#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    vector<pair<int,int>> targets;
    
    do{
        targets.clear();
        for(int i =0; i < m-1; ++i){
            for(int j = 0;j<n-1;++j){
                char c = board[i][j];
                if (c == '0') continue; 
                
                if (board[i][j+1] == c && board[i+1][j] == c && board[i+1][j+1] == c) {
                    targets.push_back({i, j});
                }
            }
        }
        
        for(auto pair : targets){
            board[pair.first][pair.second] = '0';
            board[pair.first+1][pair.second] = '0';
            board[pair.first+1][pair.second+1] = '0';
            board[pair.first][pair.second+1] = '0';
        }
        
        for(int j = 0;j<n;++j){
            int idx = m-1;
            for(int i = m-1;i>=0;--i){
                if(board[i][j] == '0') continue;
                if(idx != i){
                    board[idx][j] = board[i][j];
                    board[i][j] = '0';
                }
                --idx;
            }
        }
        
    }while(targets.size());
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '0') {
                answer++;
            }
        }
    }
    
    return answer;
}