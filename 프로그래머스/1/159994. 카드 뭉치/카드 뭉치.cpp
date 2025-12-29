#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int idx1 = 0;
    int idx2 = 0;
    int idx3 = 0;
    for(;idx3 != goal.size();){
        if(cards1[idx1] == goal[idx3]){
            ++idx1;
        }else if(cards2[idx2] == goal[idx3]){
            ++idx2;
        }else{
            return "No";
        }
        ++idx3;
    }
    return "Yes";
}