#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;


int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    
    for (int i = 0; i < citations.size(); ++i) {
        if(i >= citations[i]){
            return i;
        }
    }

    //6 5 3 3 3 3 1 0
}
