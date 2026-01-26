#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(11,0);

    int maxDiff = 0;
    for(int i =0;i<(1<<11);++i){
        int point=0;
        int enemyPoint = 0;
        int remainArrow = n;
        vector<int> record(11,0);
        int idx = i;
        for(int j = 0;j<11;++j){
            int shot = idx%2;
            if(shot && remainArrow>=info[j]+1){
                remainArrow-=(info[j]+1);
                point+=(10-j);
                record[j] = info[j]+1;
            }else{
                if(info[j]) enemyPoint+=(10-j);
            }
            idx/=2;
        }
        record[10]+=remainArrow;
        int diff = point-enemyPoint;
        if(diff<=0) continue;
        if(maxDiff<diff){
            maxDiff = diff;
            copy(record.begin(),record.end(),answer.begin());
        }else if(maxDiff==diff){
            for(int i =10;i>=0;--i){
                if(record[i]>answer[i]){
                    copy(record.begin(),record.end(),answer.begin());            
                    break;
                }
                if(record[i]<answer[i]){
                    break;
                }
            }          
        }
        
    }
    if(maxDiff==0)return{-1};
    return answer;
}