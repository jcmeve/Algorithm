#include <string>
#include <vector>
#include <queue>
using namespace std;



int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> losers(n+1);
    vector<vector<int>> winners(n+1);
    int answer = 0;
    
    for (auto& result : results) {
        losers[result[0]].push_back(result[1]);
        winners[result[1]].push_back(result[0]);
    }

    
    for(int i = 1; i <= n; ++i){
        queue<int> highers;
        queue<int> lowers;
        vector<int> visited(n+1,0);
        int highersCnt=0;
        int lowersCnt=0;
        for(int c : losers[i]){
            visited[c]=1;
            lowers.push(c);
            lowersCnt++;
        }
        
        for(int c : winners[i]){
            visited[c]=1;
            highers.push(c);
            highersCnt++;
        }
        visited[i] = 1;
        while(!highers.empty() || !lowers.empty()){
            if(!highers.empty()){
                int c = highers.size();
                for(int i =0; i < c; ++i){
                    int next = highers.front();
                    highers.pop();
                    for(auto& v : winners[next]){
                        if(!visited[v]){
                            visited[v]=1;
                            highers.push(v);
                            highersCnt++;
                        }
                    }
                }
            }  
            if(!lowers.empty()){
                int c = lowers.size();
                for(int i =0; i < c; ++i){
                    int next = lowers.front();
                    lowers.pop();
                    for(auto& v : losers[next]){
                        if(!visited[v]){
                            visited[v]=1;
                            lowers.push(v);
                            lowersCnt++;
                        }
                    }
                }
            }  
        }
        if(highersCnt+lowersCnt == n-1) answer++;
    }

    return answer;
}
