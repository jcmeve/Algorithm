#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    for(int i =0; i < name.size(); ++i){
        answer += min((name[i]-'A'), ('Z'+1-name[i]));
    }
    if(answer == 0)
        return 0;
    int a = 0;
    int b = 0;
    int t = 21341242;
    for(int i = 0; i < name.size(); ++i){
        if(name[i] != 'A')
            continue;
        int j = i;
        for(;; ++j){
            if(j == name.size()){
                if(name[j] == 'A')
                   ++j;
                break;
            }
            if(name[j] != 'A')
                break;
        }
        --j;
        //i~j A
        if(i == 0)
            i = 1;
        t = min(t,min(2*(i-1)+(int)(name.size()-j-1),(i-1)+2*(int)(name.size()-j-1)));
    }
    //JAN/AAAAAAAAAAAAAAA/ZAZ 5-1, 5-3
    for(int i =1; i < name.size(); ++i){
        if(name[i] != 'A')
            break;
        ++a;
    }
    for(int i =name.size()-1; i > 0; ++i){
        if(name[i] != 'A')
            break;
        ++b;
    }
    t = min(t, (int)name.size()-1 - max(a,b));
                
    answer+=t;
    return answer;
    
    //ABCDEFGHIJKLMNOPQRSTUVWXYZ
}