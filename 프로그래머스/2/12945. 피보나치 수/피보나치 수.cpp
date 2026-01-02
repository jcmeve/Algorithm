#include <string>
#include <vector>

using namespace std;

int cache[100001];

int F(int i){
    if(cache[i] == 0) 
        cache[i] = (F(i-1)%1234567)+(F(i-2)%1234567);
    return cache[i];
}


int solution(int n) {
    cache[2] = 1;
    cache[3] = 2;
    return F(n)%1234567;

}