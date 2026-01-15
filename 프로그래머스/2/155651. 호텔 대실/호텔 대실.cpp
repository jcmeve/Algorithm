#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<int> rooms;//outTime

    priority_queue<pair<int, int> ,std::vector<std::pair<int, int>>, greater<pair<int, int>>> sorted_book_time;

    for (const auto& vs : book_time) {
        int inTime = stoi(vs[0].substr(0, 2)) * 60 + stoi(vs[0].substr(3, 2));
        int outTime = stoi(vs[1].substr(0, 2)) * 60 + stoi(vs[1].substr(3, 2));
        sorted_book_time.push(pair<int, int>{ inTime, outTime });
    }
    while (!sorted_book_time.empty()) {
        auto pair = sorted_book_time.top();
        sorted_book_time.pop();
        for (int i = 0; i < rooms.size(); ++i) {
            if (rooms[i]+10 <= pair.first) {
                rooms[i] = pair.second;
                goto SUCC;
            }
        }
        rooms.push_back(pair.second);
    SUCC:;
    }


    return rooms.size();
}