#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size();
    int m = board[0].size();
    int answer = 0;
  
    vector<vector<int>> acc(n+1,vector<int>(m+1,0));
    
    for(auto& v : skill){
        int degree = v[5]* (v[0] == 2?1:-1);
        acc[v[1]][v[2]] += degree;
        acc[v[1]][v[4]+1] -= degree;
        acc[v[3]+1][v[2]] -= degree;
        acc[v[3]+1][v[4]+1] += degree;
    }
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            acc[i][j] += acc[i][j - 1];
        }
    }
    for (int j = 0; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            acc[i][j] += acc[i - 1][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] + acc[i][j] > 0) {
                answer++;
            }
        }
    }

    
    return answer;
}