#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    
    vector<int> c{k};
    while(k!=1){
        if(k%2){
            k*=3;
            k+=1;
        }else{
            k/=2;
        }
        c.push_back(k);
    }
    int n = c.size();
    vector<double> answer(ranges.size(),0.0);
    
    for(int i =0; i < ranges.size(); ++i){
        int l = ranges[i][0];
        int r = ranges[i][1]>0?ranges[i][1]:n+ranges[i][1]-1;     
        if(r<l){
            answer[i]=-1;
            continue;
        }
        for(int j = l;j<r;++j){
            answer[i]+=(c[j]+c[j+1])/2.0;            
        }
    }
    
    
    return answer;
}