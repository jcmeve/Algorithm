#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string* g_numbers;
int sz;
bool cache[10000000];

int is_prime(int n) {
    if (cache[n] == 0) {
        cache[n] = 1;
        return 1;
    }
    return 0;
}
int f(vector<int> indexes) {
    int ret = 0;

    int sum = 0;
    for (int i : indexes) {
        sum *= 10;
        sum += (*g_numbers)[i]-'0';
    }
    ret = is_prime(sum);
    if (indexes.size() == sz) {
        return ret;
    }
    
    for (int i = 0; i < sz; ++i) {
        if (find(indexes.begin(), indexes.end(), i) != indexes.end())
            continue;
        vector<int> t = vector<int>(indexes);
        t.push_back(i);
        ret += f(t);
    }
    return ret;
}


int solution(string numbers) {

    cache[0] = 1;
    cache[1] = 1;
    for (int i = 2; i < 10000000 / 2; ++i) {
        if (cache[i] == 1)
            continue;
        for (int j = 2; ; ++j) {
            if (i * j >= 10000000)
                break;
            cache[i * j] = 1;
        }
    }

    g_numbers = &numbers;
    sz = numbers.size();
    return f(vector<int>());
}