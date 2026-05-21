#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer={1,(int)gems.size()};
    unordered_set<string> gemType;
    for(auto& s : gems) gemType.insert(s);
    
    int nr = gemType.size();
    
    unordered_map<string,int> curr;
    int l=0;
    for(int r = 0; r < gems.size(); ++r){
        curr[gems[r]]++;
        
        while(curr.size() == nr){
            if(answer[1]-answer[0] > r-l){
                answer[1] = r+1;
                answer[0] = l+1;
            }        
            curr[gems[l]]--;
            if(curr[gems[l]]<=0)
                curr.erase(gems[l]);
            ++l;
        }
        
    }
    
    return answer;
}