#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int MM=-1;
    int Mm=-1;
    for(auto size : sizes){
        int M = max(size[0],size[1]);
        int m = min(size[0],size[1]);
        if(MM<M){
            MM=M;
        }
        if(Mm<m){
            Mm=m;
        }
    }
    
    
    return MM*Mm;
}