#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < number.size(); ++j) {
            if (j == number.size() - 1) {
                number.erase(number.begin()+j);
                break;
            }
            if (number[j] < number[j + 1]) {
                number.erase(number.begin()+j);
                break;
            }
        }
    }
    return number;
}