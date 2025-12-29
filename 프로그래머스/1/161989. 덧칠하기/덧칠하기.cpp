#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer1 = 0;
    //->
    for(int i =0; i < section.size(); ++i){
        int r = section[i]+m;
        while(i+1<section.size() && section[i+1]< r){
            ++i;
        }
        ++answer1;
    }
    
    //<-
    int answer2 = 0;
    //->
    for(int i =section.size()-1; i >=0; --i){
        int l = section[i]-m;
        while(i-1>=0 && section[i-1]> l){
            --i;
        }
        ++answer2;
    }
    return answer1<answer2?answer1:answer2;
}