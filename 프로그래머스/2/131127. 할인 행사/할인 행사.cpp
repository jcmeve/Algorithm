#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    int totaldays = 0;
    for(int i : number) totaldays+=i;
    
    vector<int> cache(discount.size(),-1);
    
    for(int i = 0; i < discount.size(); ++i){
        auto it = find(want.begin(),want.end(),discount[i]);
        if(it != want.end()){
            cache[i] = &(*it)-&(*want.begin());
        }
    }
    
    for(int i = 0; i < discount.size(); ++i){
        vector<int> pocket(want.size(),0);
        
        if(i+totaldays > discount.size())
            break;
        for(int j = 0; j < totaldays;++j){

            if(cache[i+j] == -1) {
                continue;
            }
            pocket[cache[i+j]]++;
        }

        
        for(int i =0; i < number.size(); ++i){
            if(number[i]>pocket[i]) goto FAIL;
        }
        answer++;

        FAIL:;
    }
    
    
    
    
    return answer;
}