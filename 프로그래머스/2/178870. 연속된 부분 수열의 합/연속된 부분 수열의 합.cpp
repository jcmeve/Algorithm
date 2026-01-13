#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, 0);
    
    int l = 0, r = 0;
    int acc = sequence[0];
    int length = 987654321;
    for (l = 0; l != sequence.size(); ++l) {
        if(l!=0)
            acc -= sequence[l-1];

        if (acc == k) {
            if (length > r - l + 1) {
                answer[0] = l;
                answer[1] = r;
                length = r-l+1;
            }
        }
        while (acc > k) {
            acc -= sequence[r];
            --r;
        }
        if (acc == k) {
            if (length > r - l + 1) {
                answer[0] = l;
                answer[1] = r;
                length = r-l+1;
            }
        }
        while (acc < k) {
            ++r;
            if (r >= sequence.size())
                return answer;
            acc += sequence[r];

        }
        if (acc == k) {
            if (length > r - l + 1) {
                answer[0] = l;
                answer[1] = r;
                length = r-l+1;
            }
        }

    }
    return answer;
}