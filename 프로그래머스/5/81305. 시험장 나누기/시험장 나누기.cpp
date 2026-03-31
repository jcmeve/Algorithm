#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int>* g_num;
vector<vector<int>>* g_links;

int cnt =0;

int f(int node, int maxSize){ //아래서 남겨 올라온 수 반환
    if(node == -1) return 0;
    int ret = 0;
    
    priority_queue<int> pq;//루트와 각 서브트리의 윗쫏 부분 병합 테스트
    int acc = 0;
    
    int remain_subtree1 = f((*g_links)[node][0], maxSize);
    pq.push(remain_subtree1);
    int remain_subtree2 = f((*g_links)[node][1], maxSize);
    pq.push(remain_subtree2);
    acc = remain_subtree1+remain_subtree2;
    
    while(!pq.empty() && (acc + (*g_num)[node]) > maxSize){
        acc-=pq.top();
        pq.pop();
        ++cnt;
    }
    return acc + (*g_num)[node];
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    g_num = &num;
    g_links = &links;
    
    int rootIdx = links.size()*(links.size()-1)/2;
    for(const auto& childs : links){
        if(childs[0]>0) rootIdx-=childs[0];
        if(childs[1]>0) rootIdx-=childs[1];
    }

    int low = *max_element(num.begin(), num.end());
    int high = 0;
    for (int x : num) high += x;
    
    int answer = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        cnt = 0;
        
        f(rootIdx, mid);
        
        if (cnt + 1 <= k) {
            answer = mid;   
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }
    
    
    cout<<answer;
    
    return answer;
}