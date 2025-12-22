#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0;
    for(int temp = x; temp>0; temp/=10)
        sum+=temp%10;
    return !(x%sum);
}