#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const vector<string>& a, const vector<string>& b){
    string ta = a[0];
    string tb = b[0];
    
    for(char& c : ta)
        if(c>'Z') c-='a'-'A'; 
    for(char& c : tb)
        if(c>'Z') c-='a'-'A';
    if(ta!=tb){
        return ta<tb;
    }
    return stoi(a[1])<stoi(b[1]);
    
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<vector<string>> tks(files.size(),vector<string>(3,""));
    for(int idx = 0; idx < files.size(); ++idx) {
        string file = files[idx];
        
        int NUMBER = -1;        
        int TAIL = -1;        
        for(int i = 0; i < file.size(); ++i){
            if(file[i]>= '0' && file[i]<='9'){
                NUMBER = i;
                break;
            }
        }
        for(int i = NUMBER; i < file.size(); ++i){
            if(file[i]< '0' || file[i]>'9'){
                TAIL = i;
                break;
            }
        }
        if(TAIL == -1) {
            TAIL = file.size();
        }
        tks[idx][0] = (file.substr(0,NUMBER));
        tks[idx][1] = (file.substr(NUMBER,TAIL-NUMBER));
        tks[idx][2] = (file.substr(TAIL));
        
    }
    stable_sort(tks.begin(),tks.end(),&comp);
    for(int i = 0; i < tks.size(); ++i){
        answer.push_back(tks[i][0]+tks[i][1]+tks[i][2]);
    }
    return answer;
}