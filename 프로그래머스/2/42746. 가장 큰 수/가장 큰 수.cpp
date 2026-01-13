#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(int a, int b) {
    if (a == b)
        return false;
    if (a == 0)
        return false;
    if (b == 0)
        return true;

    int a_ten = 10000;
    int b_ten = 10000;
    for (; 0 == a / a_ten; a_ten /= 10);
    for (; 0 == b / b_ten; b_ten /= 10);

    int ab = a * b_ten*10 + b;
    int ba = b * a_ten*10 + a;;
    return ab > ba;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), comp);
    if(numbers[0] == 0)
        return answer+"0";
    for (int i : numbers) {
        answer += to_string(i);
    }
    return answer;
}