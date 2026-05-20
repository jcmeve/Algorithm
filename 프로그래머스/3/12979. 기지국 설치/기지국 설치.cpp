#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int l = 0;
    for(int i = 0; i < stations.size(); ++i){
        int r = stations[i]-w;
        int length = r-l-1;
        if(length>0)
            answer+=(length-1)/(w*2+1)+1;
        l = stations[i]+w;
    }
    int r = n+1;
    int length = r-l-1;
    if(length>0)
        answer+=(length-1)/(w*2+1)+1;
    
    

    return answer;
}