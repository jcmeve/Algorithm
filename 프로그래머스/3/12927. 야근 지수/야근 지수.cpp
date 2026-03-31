#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq(works.begin(),works.end());
    
    for(int i =0; i < n; ++i){
        int temp = pq.top();
        pq.pop();
        pq.push(temp-1);
    }
    while(!pq.empty()){
        int temp = pq.top();
        pq.pop();
        if(temp>0) answer+=temp*temp;
    }
    return answer;
}