#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int p=0;
    int y=0;
    for(char c : s){
        if(c=='p'||c=='P'){
            ++p;
        }
        if(c=='y'||c=='Y'){
            ++y;
        }
    }
    return p==y;
    
}