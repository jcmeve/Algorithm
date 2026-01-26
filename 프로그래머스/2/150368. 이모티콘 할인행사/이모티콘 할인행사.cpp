#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer={0,0};
    
    int arr[]={10,20,30,40};
    
    for(int i = 0;i < 4<<2*(emoticons.size()-1);++i){
        vector<int>ratio;
        int idx = i;
        for(int j = 0; j <emoticons.size();++j){
            ratio.push_back(arr[idx%4]);
            idx/=4;
        }
        int subCnt = 0;
        int totalSell = 0;
        for(auto& user : users){
            int userSell = 0;
            for(int j = 0;j<emoticons.size();++j){
                if(user[0]<=ratio[j]){
                    userSell+=emoticons[j]/100*(100-ratio[j]);
                    if(userSell>=user[1]){
                        subCnt++;
                        goto SUB;
                    }
                }
            }
            totalSell+=userSell;
            SUB:;
        }
        if(answer[0]<subCnt){
            answer[0] = subCnt;
            answer[1] = totalSell;
        }if(answer[0] == subCnt){
            answer[1] = answer[1]>totalSell?answer[1]:totalSell;
        }

    }
    
    return answer;
}