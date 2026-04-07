#include <iostream>
using namespace std;
int m[26] = { 0, },n, f,c;
int main() {
    cin >> n;
    while (n--) {
        string temp;
        cin >> temp;
        m[temp[0] - 'a']++;
    }
    for (c = 0; c < 26; ++c)
        if (m[c] >= 5) {
            f = 1;
            cout << (char)(c + 'a');
        }
    if (!f) cout << "PREDAJA";
}