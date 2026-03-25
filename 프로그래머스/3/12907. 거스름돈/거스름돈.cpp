#include <string>
#include <vector>
using namespace std;


int solution(int n, vector<int> money) {
    vector<int> cache(n+1,0);
    cache[0] = 1;
    for(int currMoney : money){
        for(int i = currMoney; i<=n; ++i){
            cache[i]+=cache[i-currMoney];
            cache[i]%=1000000007;
        }
    }
    return cache[n];
}