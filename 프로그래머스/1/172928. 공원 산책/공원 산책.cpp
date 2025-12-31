#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int y,x;
    for(y = 0; y < park.size(); y++){
        for(x = 0; x < park[y].size(); x++){
            if(park[y][x] == 'S')
                goto next;
        }
    }
next:
    
    for(const string& route : routes){
        vector<int> move_dir;
        switch(route[0]){
            case 'E':
                move_dir = {0,1};
                break;
            case 'W':
                move_dir = {0,-1};
                break;
            case 'S':
                move_dir = {1,0};
                break;
            case 'N':
                move_dir = {-1,0};
                break;
        }
        int dist = (route[2]-'0');
        int y_cal = y;
        int x_cal = x;
        int i;
        for(i = 0; i < dist; i++){
            y_cal += move_dir[0];
            x_cal += move_dir[1];
            if(y_cal == park.size() || y_cal <0 || x_cal == park[0].size() || x_cal <0 || park[y_cal][x_cal] == 'X'){
                break;
            }
        }
        if(i == dist){
            x = x_cal;
            y = y_cal;
        }
    }
    answer = {y,x};
    return answer;
}