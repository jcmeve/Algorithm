#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    vector<int> v;
    unsigned long long acc=0;
    for(int i =0;i < enemy.size(); ++i){
        
        acc+=enemy[i];
        v.push_back(enemy[i]);
        push_heap(v.begin(),v.end());
        
        while(acc>n && k>0 && !v.empty()){
            pop_heap(v.begin(),v.end());
            acc-=v[v.size()-1];            
            v.pop_back();
            --k;
        }
        if(acc>n)
        {

            break;
            
        }
        ++answer;

    }

    
    return answer;
}