#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto& place : places){
        for(int y = 0; y < place.size(); ++y){
            for(int x = 0; x < place[0].size(); ++x){
                if(place[y][x] != 'P') continue;
                
                if(y-1>=0&& place[y-1][x] == 'P') goto NEXT;
                if(y+1<place.size()&& place[y+1][x] == 'P') goto NEXT;
                if(x-1>=0&& place[y][x-1] == 'P') goto NEXT;
                if(x+1<place[0].size()&& place[y][x+1] == 'P') goto NEXT;                

                if(y-1>=0 && x-1>=0&& place[y-1][x-1] == 'P')
                    if(place[y][x-1] != 'X' || place[y-1][x] != 'X') goto NEXT;
                if(y-1>=0 && x+1<place[0].size()&& place[y-1][x+1] == 'P')
                    if(place[y][x+1] != 'X' || place[y-1][x] != 'X') goto NEXT;    
                if(y+1<place.size() && x-1>=0&& place[y+1][x-1] == 'P')
                    if(place[y][x-1] != 'X' || place[y+1][x] != 'X') goto NEXT;    
                if(y+1<place.size() && x+1<place[0].size()&& place[y+1][x+1] == 'P')
                    if(place[y][x+1] != 'X' || place[y+1][x] != 'X') goto NEXT;    


                if(y-2>=0&& place[y-2][x] == 'P')
                    if(place[y-1][x] != 'X') goto NEXT;
                
                if(y+2<place.size()&& place[y+2][x] == 'P')
                    if(place[y+1][x] != 'X') goto NEXT;
                
                if(x-2>=0&& place[y][x-2] == 'P')
                    if(place[y][x-1] != 'X') goto NEXT;
                    
                if(x+2<place[0].size()&& place[y][x+2] == 'P')
                    if(place[y][x+1] != 'X') goto NEXT;
            }        
        }
        answer.push_back(1);
        continue;
        NEXT:;
        answer.push_back(0);
    }
    return answer;
}