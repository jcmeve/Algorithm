#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0;i<commands.size();i++){
        vector<int> temp;
        for(int j=commands[i][0]-1;j<commands[i][1];j++)
            temp.push_back(array[j]);
        for(int j=0;j<temp.size();j++){//sort
            for(int k=j;k<temp.size();k++){
                if(temp[k]<temp[j]){
                    int T=temp[j];
                    temp[j]=temp[k];
                    temp[k]=T;
                }
            }
        }
        answer.push_back(temp[commands[i][2]-1]);
    }
    return answer;
}