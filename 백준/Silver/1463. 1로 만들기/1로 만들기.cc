#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int cache[1000001];


int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    v[1] = 0;
    for (int i = 2; i <= n; ++i) {
        v[i] = v[i - 1];
        if (i % 2 == 0) {
            v[i] = min(v[i],v[i / 2]);
        }
        if (i % 3 == 0) {
            v[i] = min(v[i],v[i / 3]);
        }
        v[i] += 1;
    }

    cout << v[n];
}