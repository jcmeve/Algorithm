#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) { 
    int curr_weight=0;
    int curr_time=0;
    int answer =0 ;
    queue<pair<int,int>> q;
    for(int i = 0; i < truck_weights.size(); ++i){
        curr_time++;
        if(!q.empty() && q.front().second<=curr_time){
            curr_weight-=q.front().first;

            q.pop();
        }
        
        
        if(truck_weights[i]+curr_weight <=  weight){
            q.push({truck_weights[i],curr_time+bridge_length});
            curr_weight+=truck_weights[i];
        }else{
            --i;
        }

        
    }
    if(!q.empty()){
        while(q.size() != 1) q.pop();
        answer = q.front().second;
    }
    return answer;
}