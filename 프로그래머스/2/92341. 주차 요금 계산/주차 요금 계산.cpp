#include <string>
#include <vector>
#include <map>
using namespace std;



vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int baseTime = fees[0];
    int baseFee = fees[1];
    int term = fees[2];
    int fee = fees[3];

    map<string,int> m; //stack
    map<string,int> m_answer;
    
    for(int i =0; i < records.size();++i){
        int currTime =  stoi(records[i].substr(0,2))*60+stoi(records[i].substr(3,2));
        if(records[i][11] == 'O'){
            m_answer[ records[i].substr(6,4)] += currTime -m[records[i].substr(6,4)];
            m[records[i].substr(6,4)]=-1;
        }else{
            m[records[i].substr(6,4)] = currTime;
        }
    }
    
    for(auto v : m){
        if(m[v.first] != -1){
            m_answer[ v.first] += (24*60-1) -m[v.first];
        }
    }
  
    
    for(auto v : m_answer){
        int totalTime = m_answer[ v.first]-baseTime;
        int price = baseFee;
        if(totalTime>0){
           price+= (totalTime+term-1)/term*fee;
        }
        answer.push_back(price);
    }
    
    return answer;
}