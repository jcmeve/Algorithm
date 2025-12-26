#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int gN;
bool compare(const string& a, const string& b){
    if(a[gN]!=b[gN]) return a[gN]<b[gN];
    return a<b;
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    gN = n;
    sort(strings.begin(), strings.end(),compare);
    return strings;
}