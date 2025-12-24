#include <string>
#include <vector>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    for(int i =0; i < t.size()-p.size()+1; ++i){
        for(int j = 0; j < p.size(); ++j){
            if(t[i+j]>p[j])
                goto solution_out;
            if(t[i+j]<p[j])
                break;
        }
        ++answer;
solution_out:;
    }
    
    
    return answer;
}