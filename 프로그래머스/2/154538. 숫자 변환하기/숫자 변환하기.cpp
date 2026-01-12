#include <string>
#include <vector>
#include <queue>
using namespace std;

int cache[1000001];
int solution(int x, int y, int n) {

    queue<int> q;
    int cnt = 0;
    q.push(x);
    for(;;){
        if(q.empty())
            return-1;
        int t = q.front();
        q.pop();
        if(t == y)
            return cache[t];
        if(t>y)
            continue;

        
        if(t+n<=y && (cache[t+n]==0 || (cache[t+n]>cache[t]+1))){
            cache[t+n] = cache[t]+1;
            q.push(t+n); 
        }
        if(2*t<=y && (cache[2*t]==0 || (cache[2*t]>cache[t]+1))){
            cache[2*t] = cache[t]+1;
            q.push(2*t); 
        }
        if(3*t<=y && (cache[3*t]==0 || (cache[3*t]>cache[t]+1))){
            cache[3*t] = cache[t]+1;
            q.push(3*t); 
        }
        
    }
    
    return -1;
}