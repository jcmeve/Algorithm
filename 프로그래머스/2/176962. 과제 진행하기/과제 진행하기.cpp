#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int timeConvert(const string& timeline){
    return stoi(timeline.substr(0,2))*60+stoi(timeline.substr(3,2));
}

bool comp(const vector<string>& a,const vector<string>& b){
    return timeConvert(a[1])<timeConvert(b[1]);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(),plans.end(),comp);
     
    stack<pair<string, int>> s;//name,remain
    int currTime = 0;

    for(int i = 0; i < plans.size(); ){
        //다음 과제 전 끝내는지 처리
        //다음 과제가 있으면 push
        //아직 시작시간 안됐으면 걍 continue;
        if(s.empty()){
            currTime = timeConvert(plans[i][1]);
            s.push({plans[i][0],stoi(plans[i][2])});
            ++i;
            continue;
        }
        
        if(currTime + s.top().second <= timeConvert(plans[i][1])){
            currTime += s.top().second;
            answer.push_back(s.top().first);
            s.pop();
            continue;
        }else{
            s.top().second -= (timeConvert(plans[i][1])-currTime);
            currTime = timeConvert(plans[i][1]);
            s.push({plans[i][0],stoi(plans[i][2])});
            ++i;
        }



    }
    
    while(!s.empty()){
        answer.push_back(s.top().first);
        s.pop();
    }
    
        
    return answer;
}