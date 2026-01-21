#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include<iostream>
using namespace std;

bool comp(const vector<int>& a,const vector<int>& b){
    if(a[0]!=b[0])
        return a[0]>b[0];
    if(a[1]!=b[1])
        return a[1]>b[1];
    return a[2]>b[2];
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int dia = picks[0];
    int iron = picks[1];
    int stone = picks[2];
    
    vector<map<string,int>> m(3);
    m[0]["diamond"]=1;
    m[0]["iron"]=1;
    m[0]["stone"]=1;
   
    m[1]["diamond"]=5;
    m[1]["iron"]=1;
    m[1]["stone"]=1;
    
    m[2]["diamond"]=25;
    m[2]["iron"]=5;
    m[2]["stone"]=1;
    
    
    minerals.erase(minerals.begin()+min(((size_t)dia+iron+stone)*5,minerals.size()),minerals.end());
    while(minerals.size()%5)
        minerals.push_back("");
    
    
    vector<vector<int>> tokens(minerals.size()/5,vector<int>(3,0));//d,i,s
    for(int i =0;i<minerals.size()/5;++i){
        for(int j = 0;j<5;++j){
            if(minerals[i*5+j] == "diamond"){
                tokens[i][0]++;                 
            }else if(minerals[i*5+j] == "iron"){
                tokens[i][1]++;                 
            }else if(minerals[i*5+j] == "stone"){
                tokens[i][2]++;                 
            }
        }
    }
    sort(tokens.begin(),tokens.end(),comp);
    
    int idx = 0;
    for(int i =0; i < dia;++i){
        answer+=tokens[idx][0];
        answer+=tokens[idx][1];
        answer+=tokens[idx][2];
        ++idx;
        if(idx == tokens.size())
            return answer;
    }
    for(int i =0; i < iron;++i){
        answer+=5*tokens[idx][0];
        answer+=1*tokens[idx][1];
        answer+=1*tokens[idx][2];
        ++idx;
        if(idx == tokens.size())
            return answer;
    }

    for(int i =0; i < stone;++i){
        answer+=25*tokens[idx][0];
        answer+=5*tokens[idx][1];
        answer+=1*tokens[idx][2];
        ++idx;
        if(idx == tokens.size())
            return answer;
    }

    
    return answer;
}