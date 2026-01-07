#include <string>
#include <vector>
#include <set>
using namespace std;
int solution(vector<int> elements) {
    set<int> sums;
    //[i][j] : sum(j~j+i)
    vector<vector<int>> cache (elements.size(),vector<int>(elements.size(),0));
    std::copy(elements.begin(),elements.end(), cache[0].begin());
    for(int i : elements) sums.insert(i);
    for(int i =1; i < elements.size(); ++i){
        for(int j = 0; j < elements.size(); ++j){       
            cache[i][j] = cache[i-1][j]+cache[0][(j+i)%elements.size()];
            sums.insert(cache[i][j]);

        }
    }

    return sums.size();
}