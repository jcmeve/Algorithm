#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int getTime(string& time){
    return stoi(time.substr(0,2))*60 + stoi(time.substr(3,5));
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> tt;
    for(auto& s : timetable) tt.push_back(getTime(s));
    sort(tt.begin(),tt.end());
    
    int startTime = 9*60;
    int ttIndex = 0;
    int answerTime = 0;
    for(int i =0; i < n; ++i){
        int currN = 0;
        for(; currN<m;++currN){
            if(ttIndex>=tt.size()) break;
            if(tt[ttIndex] > startTime) break;
            ttIndex++;
        }
        if(i == n-1){
            if(currN<m){
                answerTime = startTime;
            }else{
                answerTime = tt[ttIndex-1]-1;
            }
        }
        startTime += t;
    }
    char buffer[6];
    sprintf(buffer, "%02d:%02d", answerTime/60,answerTime%60);
    
    return buffer;
}