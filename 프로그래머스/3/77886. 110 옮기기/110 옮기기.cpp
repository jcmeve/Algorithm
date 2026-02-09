#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for (int i = 0; i < s.size(); ++i) {
        //dest = 맨 끝 0의 뒤 or맨앞 
        string temp;
        int cnt = 0;
        for(char c : s[i]){
            if(temp.size()>=2 && c == '0' && temp[temp.size()-1] == '1' && temp[temp.size()-2] == '1' ){
                ++cnt;
                temp.erase(temp.size()-2,2);
                continue;
            }
            temp+=c;
        }
        
        int idx = temp.rfind('0');
        string tokens;
        for(int i =0; i < cnt; ++i){
            tokens+="110";
        }
        string result;
        if(idx == string::npos){
            result = tokens+temp;
        }else{
            result = temp.substr(0,idx+1)+tokens+temp.substr(idx+1);
        }
        answer.push_back(result);
        

    }


    return answer;
}