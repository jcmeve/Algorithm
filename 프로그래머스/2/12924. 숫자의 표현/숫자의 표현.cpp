#include <string>
using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 1; i <= n; ++i){
        if(i%2){
            if(n%i == 0){
                int mid = n/i;
                if(mid - (i/2) >= 1 && mid + (i/2) <= n)
                    ++answer;
            }
        }else{
            if(n%i != i/2) continue;
            int l = n/i;
            if(l - (i/2-1)>=1)
                ++answer;
        }
    }
    return answer;
}