#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> cards) {
    vector<int> group(cards.size(), 0);
    int nr_group = 1;
    for (int i = 0; i < cards.size(); ++i) {
        if (group[i])
            continue;
        if (group[cards[i] - 1]) {
            group[i] = group[cards[i] - 1];
            continue;
        }
        group[i] = nr_group++;
        int curr = cards[i]-1;
        while (group[curr] != nr_group) {
            group[curr] = nr_group;
            curr = cards[curr]-1;
        }

    }

    vector<int> cache(nr_group+1, 0);
    for (int i : group)
        cache[i]++;

    int M = 0;
    int prevM = M;
    for (int i = 1; i < cache.size(); ++i) {
        if (M < cache[i]) {
            prevM = M;
            M = cache[i];
        }
        else if (prevM < cache[i]) {
            prevM = cache[i];
        }
    }

    return prevM * M;
}