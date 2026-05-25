#include <string>
#include <set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    pair<int,int> curr;
    set<pair<pair<int,int>,pair<int,int>>> s;
    for(int i = 0; i < dirs.size(); ++i){
        int dy = 0;
        int dx = 0;
        switch(dirs[i]){
            case 'U':dy=-1;
                break;
            case 'L':dx=-1;
                break;
            case 'R':dx=1;
                break;
            case 'D':dy=1;
                break;
        }
        pair<int,int> next(curr.first+dy,curr.second+dx);
        if(next.first<-5 || next.first>5||next.second<-5||next.second>5) continue;

        s.insert({min(curr,next),max(curr,next)});
        curr.first = next.first;
        curr.second = next.second;
    }
    
    return s.size();
}