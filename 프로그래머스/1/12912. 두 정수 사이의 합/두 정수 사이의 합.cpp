#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long lla = a;
    long long llb = b;
    
    if(lla>llb){
        swap(lla,llb);
    }else if(lla == llb){
        return lla;
    }
    
    return (lla+llb)*(llb-lla+1)/2;
}