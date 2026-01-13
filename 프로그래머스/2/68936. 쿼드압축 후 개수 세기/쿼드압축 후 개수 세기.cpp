#include <string>
#include <vector>

using namespace std;

int nr1=0;
int nr0=0;
vector<vector<int>>* g_arr;

void f(int x_start, int y_start, int length){
    if(length == 1) return;
    int cnt1=0;
    int cnt0=0;
    for(int y = y_start; y<y_start+length;++y){
        for(int x= x_start; x<x_start+length; ++x){
            if((*g_arr)[y][x] == 1) {
                if(cnt0 != 0)
                    goto FAIL;
                cnt1++;
            }else{
                if(cnt1!=0)
                    goto FAIL;
                cnt0++;
            }
        }
    }
    if(cnt1 == length*length)
        nr1-=(length*length-1);
    
    if(cnt0 == length*length)
        nr0-=(length*length-1);
    return;
    FAIL:;
    
    f(x_start,y_start, length/2);
    f(x_start+length/2,y_start, length/2);
    f(x_start+length/2,y_start+length/2, length/2);
    f(x_start,y_start+length/2, length/2);
}



vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    g_arr = &arr;
    for(int i =0; i<arr.size(); ++i){
        for(int j =0;j<arr[0].size(); ++j){
            if(arr[i][j] == 1)nr1++;
            else nr0++;
        }
    }
    
    f(0,0,arr.size());
    
    
    return {nr0,nr1};
}