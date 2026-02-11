#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    //dlru
    int shortest = abs(r-x)+abs(c-y);
    if(shortest%2 != k%2 || shortest>k){
        return "impossible";
    }
    
    while(k-1 >= abs(r-x)+abs(c-y)){
        if(x != n){
            x+=1;
            k-=1;
            answer+='d';
            continue;
        }    
        if(y!=1){
            y-=1;
            k-=1;
            answer+='l';
            continue;
        }
        if(y!=m){
            y+=1;
            k-=1;
            answer+='r';
            continue;            
        }
    }   
    for(int i =0; i < r-x; ++i){
        answer+='d';
    }
    for(int i =0; i < y-c; ++i){
        answer+='l';
    }  
    for(int i =0; i < c-y; ++i){
        answer+='r';
    }    
    for(int i =0; i < x-r; ++i){
        answer+='u';
    }
    return answer;
}