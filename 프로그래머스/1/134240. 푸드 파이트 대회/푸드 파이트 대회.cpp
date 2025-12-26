#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for (int i = 0; i < food.size(); ++i) {
        answer.append(food[i] /2, i + '0');
    }
   
    string temp = answer;
    reverse(temp.begin(), temp.end());
     answer += '0';
    answer.append(temp);

    return answer;
}