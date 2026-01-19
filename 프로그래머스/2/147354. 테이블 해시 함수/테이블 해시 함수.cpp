#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int g_col;
bool comp(const vector<int>& a,const vector<int>& b){
    if(a[g_col] != b[g_col])
        return a[g_col]<b[g_col];
    return a[0]>b[0];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    g_col = col-1;
    row_begin-=1;
    row_end-=1;
    
    sort(data.begin(),data.end(),comp);
    
    for(int i = row_begin; i<=row_end;++i){
        int S_i=0;
        for(int e : data[i]){
            S_i += e%(i+1);
        }
        answer ^= S_i;
    }
    
    
    return answer;
}