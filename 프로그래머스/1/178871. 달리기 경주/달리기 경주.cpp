#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer(players.size());
    
    map<string, int> player_idx;
    for (int i = 0; i < players.size(); ++i) {
		player_idx.insert({ players[i],i });
	}
    
    vector<int>  rating(players.size());
    
    for(int i = 0; i < players.size(); i++){
        rating[i] = i;
    }
    
    for(int i = 0; i< callings.size(); i++){
        int idx = player_idx.find(callings[i])->second;
        int curr_rating;
        for(curr_rating = 0; curr_rating < rating.size();curr_rating++){
            if(rating[curr_rating] == idx)
                break;
        }
        swap(rating[curr_rating],rating[curr_rating-1]);
    }
    
    for (auto iter = player_idx.begin(); 
         iter != player_idx.end(); iter++) {
        int idx = iter->second;
        for(int i = 0; i < rating.size();i++){
            if(rating[i] == idx){
                answer[i] = iter->first;   
            }
        }
	}
    
    return answer;
}