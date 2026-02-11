#include <string>
#include <vector>
#include <bitset>
using namespace std;

int f(const bitset<64>& tree, int l, int r, bool isParentZero) {
    int m = (r + l) / 2;
    if (tree.test(m) && isParentZero)
        return 0;
    if(r == l )
        return 1;
    return  f(tree, l, m - 1, !tree.test(m)) && f(tree, m + 1, r,!tree.test(m));
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (long long number : numbers) {
        int nr_bit = 0;
        for (long long i = 1; (number - 1) / i != 0; i *= 2) {
            nr_bit++;
        }
        for (int i = 2; ; i *= 2) {
            if (nr_bit / (i - 1) == 0 || nr_bit == (i - 1)) {
                nr_bit = i - 1;
                break;
            }
        }
        bitset<64> b(number);

        answer.push_back(f(b, 0, nr_bit-1,false));
    }

    return answer;
}