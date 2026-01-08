#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    if(a[0] == b[0])
        return a[1]>b[1];
    return a[0]>b[0];
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    sort(dungeons.begin(), dungeons.end(), &compare);
    do{

        int s = 0;
        for(int i = 0 ; i < dungeons.size(); ++i){
            if(s + dungeons[i][0] > k){
                answer = answer>i?answer:i;
                break;
            }
            s+=dungeons[i][1];
            if( i == dungeons.size()-1){
                return i+1;
            }
        }
        
    }while(next_permutation(dungeons.begin(), dungeons.end(), &compare));
    
    return answer;
}