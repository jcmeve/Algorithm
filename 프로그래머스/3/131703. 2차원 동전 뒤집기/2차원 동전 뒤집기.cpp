#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 1000;
    //각 열행 두번 뒤집는건 하등 의미없음
    //최대 횟수는 n*n 이 때 뒤집는 총 개수 n*n*n < 작음
    int nr_row = beginning.size();
    int nr_col = beginning[0].size();
    //뒤집어야 할 부분을 표시하고 
    //각 열을 뒤집어서 행의 목표뒤집기를 맞추든 그 역을 맞춰야함
    vector<vector<int>> flipTargets(nr_row,vector<int>(nr_col, 0));
    for(int y = 0; y < nr_row;++y){
        for(int x = 0; x < nr_col;++x){
            flipTargets[y][x] = (beginning[y][x]!=target[y][x])?1:0;
        }
    }
    for(int yState = 0; yState<(1<<nr_row);++yState){
        int row_flips = 0;
        int col_flips = 0;
        bool flag = true;
        for(int y = 0; y < nr_row; y++) {
            if((yState >> y) & 1) row_flips++;
        }
        for(int x = 0; x < nr_col; ++x){
            int cnt = 0;
            for(int y = 0; y < nr_row; ++y) {
                if(flipTargets[y][x] == (yState>>y&1)) cnt++;
            }
            if(cnt!= 0 && cnt != nr_row) {flag = false;break;}
            if(cnt == 0){
                col_flips++;
            }else if(cnt == nr_row){
                continue;
            }
        }
        if(!flag) continue;
        int flips = row_flips + col_flips;
        answer = answer>flips?flips:answer;

        
        FAIL:;
    }
    
    return answer==1000?-1:answer;
}