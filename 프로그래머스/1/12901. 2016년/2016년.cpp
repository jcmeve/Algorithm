#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    
    string day[7] ={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    

    int days = b + 4;
    for(int i = 1; i < a;i++)
        days += month[i-1];
    
    days%=7;
    answer = day[days];
    return answer;
}