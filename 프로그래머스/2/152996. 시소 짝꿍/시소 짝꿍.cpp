#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long cache[2001];

long long solution(vector<int> weights) {
    long long answer = 0;
    for(int i = 0; i < 2001;++i)
       cache[i]=0;
    for (int i : weights) {
        cache[i]++;
    }

    
    for (long long curr = 100; curr <= 1000; ++curr) {
        long long nr = cache[curr];
        if(nr == 0 )continue;
        
        long long target = curr;
        answer += nr*(nr-1) /2;

        if(curr*3%2==0){
            target = curr * 3/2;
            answer += cache[target]*nr;
            
        }
        
        target = curr * 2;
        answer += cache[target]*nr;
        
        if(curr*4%3==0){
            target = curr * 4/3;
            answer += cache[target]*nr;
        }
    }




    return answer;
}