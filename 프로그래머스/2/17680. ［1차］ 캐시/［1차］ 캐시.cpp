#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    map<string, int> m;
    for (int i = 0; i < cities.size(); ++i) {

        string city = cities[i];
        for (char& c : city) {
            c = tolower(c);
        }
        if (m.find(city) != m.end()) {
            ++answer;
            m[city]=i;
        }
        else {
            answer += 5;

            
            m[city] = i;
            
            while (m.size() > cacheSize) {
                int least = 987654321;
                string key;
                for (auto& p : m) {
                    if (p.second < least) {
                        least = p.second;
                        key = p.first;
                    }
                }
                m.erase(key);
            }

        }
    }

    return answer;
}