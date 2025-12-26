#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> ranker;
    int currMin = 987654321;
    for (int i = 0; i < k && i<score.size(); ++i) {
        currMin = min(currMin, score[i]);
        answer.push_back( currMin);

        ranker.push_back(score[i]);
        make_heap(ranker.begin(), ranker.end(), greater<int>());
    }

    for (int i = k; i < score.size(); ++i) {
        if (ranker[0] < score[i]) {
            ranker[0] = score[i];
            make_heap(ranker.begin(), ranker.end(), greater<int>());
        }
        answer.push_back(ranker[0]);
    }
    return answer;
}