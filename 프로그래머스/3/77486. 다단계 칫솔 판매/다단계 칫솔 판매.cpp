
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(),0);
    unordered_map<string, int> name_to_idx;
    vector<int> parents(enroll.size(),-1);
    for (int i = 0; i < enroll.size();++i) {
        name_to_idx[enroll[i]] = i;
    }
    for (int i = 0; i < enroll.size(); ++i) {
        if (referral[i] != "-")
            parents[i] = name_to_idx[referral[i]];
    }
    
    for (int i = 0; i < seller.size(); ++i) {
        int currIdx = name_to_idx[seller[i]];
        int upGold = amount[i]*100;
        while (currIdx != -1 && upGold) {
            int tax = upGold / 10;
            answer[currIdx] += upGold - tax;
            upGold = tax;
            currIdx = parents[currIdx];
        }
    }
    

    return answer;
}

