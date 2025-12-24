#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int m1=0,m2=0;
    for(int i = 0; i < sizes.size(); ++i){
        int a = sizes[i][0]>sizes[i][1]?sizes[i][0]:sizes[i][1];
        int b = sizes[i][0]+sizes[i][1]-a;
        if(m1 < a){
            m1 = a;
        }
        if(m2<b){
            m2 = b;
        }
        
        
    }
    return m1*m2;
}