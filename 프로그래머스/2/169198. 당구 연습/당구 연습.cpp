#include <string>
#include <vector>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
        
    for(const auto& ball : balls){
        int ballX = ball[0];
        int ballY = ball[1];
        int res = 987654321;
        
        
        if (!(startY == ballY && startX > ballX)) 
            res = min(res, (startX + ballX) * (startX + ballX) + (startY - ballY) * (startY - ballY));
        if (!(startY == ballY && startX < ballX)) 
            res = min(res, (2 * m - startX - ballX) * (2 * m - startX - ballX) + (startY - ballY) * (startY - ballY));
        if (!(startX == ballX && startY > ballY)) 
            res = min(res, (startX - ballX) * (startX - ballX) + (startY + ballY) * (startY + ballY));
        if (!(startX == ballX && startY < ballY)) 
            res = min(res, (startX - ballX) * (startX - ballX) + (2 * n - startY - ballY) * (2 * n - startY - ballY));
        
        
        answer.push_back(res);
    }
    return answer;
}