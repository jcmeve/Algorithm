#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(int N, int number) {
    vector<set<int>> s(9);
    int acc = 0;
    for(int i = 1; i <= 8; ++i){
        acc = acc*10+N;
        s[i].insert(acc);
        if(acc == number)
            return i;
    }
    
    for(int i = 1; i<=8;++i){
        for(int j = 1; j <i; ++j){
            for(int a : s[i-j]){
                for(int b : s[j]){
                    if(a+b == number) return i;
                    s[i].insert(a+b);
                    if(a-b == number) return i;
                    s[i].insert(a-b);
                    if(a*b == number) return i;
                    s[i].insert(a*b);
                    if(b==0)continue;
                    if(a/b == number) return i;
                    s[i].insert(a/b);
                }
            }
        }
    }
    
    return -1;
}