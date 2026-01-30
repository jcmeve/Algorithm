#include <string>
#include <vector>

using namespace std;
vector<vector<int>> Mul(const vector<vector<int>>& a, const vector<vector<int>>& b, bool* isChange){
    vector<vector<int>> ret(a.size(), vector<int>(b[0].size()));
    
    for(int i = 0; i<a.size();i++){
        for(int j = 0; j<b[0].size();j++){
            for(int k = 0; k<a[0].size();k++){
                if(a[i][k] == 1 && 1 == b[k][j]){
                    ret[i][j] = 1;
                    if(a[i][j] != ret[i][j])
                        *isChange = true;
                    break;
                }
            }
        }
    }
    return ret;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<vector<int>> Matrix(computers);
    while(true){
        bool isChange = false;
        Matrix = Mul(Matrix,computers,&isChange);
        if(!isChange)
            break;
    }
    
    vector<bool> vertex(computers.size(),false);//탐색완료시 true
    for(int i = 0; i< computers.size(); i++){
        if(vertex[i] == true){
            continue;
        }
        for(int j = 0; j<computers.size();j++){
            if(Matrix[i][j] == 1){
                vertex[j]  = true;
            }
        }
        answer ++;
        
    }
    
    
    
    return answer;
}