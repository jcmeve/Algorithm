#include <string>
#include <vector>
using namespace std;


string f(string s) {
    int cnt = 0;
    int i = 0;
    bool correct = true;
    for (i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            ++cnt;
        }
        else {
            --cnt;
        }
        if (cnt < 0) {
            correct = false;
        }
        if (cnt == 0) {
            break;
        }
    }
    if (correct) {
        if (i == s.size()) return s;
        string temp(s.begin(), s.begin() + i+1);
        string temp2 = string(s.begin() + i+1, s.end());
        return temp + f(temp2);
    }
    else {
        string u(s.begin() + 1, s.begin() + i );
        for (int j = 0; j < u.size(); ++j) {
            if (u[j] == '(') u[j] = ')';
            else if (u[j] == ')') u[j] = '(';
        }
        string temp = string(s.begin()+i+1, s.end());
        return '(' + f(temp) + ')' + u;
    }
}

string solution(string p) {
    return f(p);
}