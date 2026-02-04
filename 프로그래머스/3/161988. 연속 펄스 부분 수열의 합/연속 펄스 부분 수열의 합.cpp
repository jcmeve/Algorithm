#include <string>
#include <vector>
using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;

    long long last = -sequence[0];
    vector<long long> v;
    for(int i =0; i < sequence.size(); ++i){    
        long long curr = sequence[i]*((i%2)?-1:1);
        if(last*curr>0){
            v[v.size()-1] += curr;   
        }else{
            v.push_back(curr);
        }
        last = curr;
    }

    for(int i = 0; i < v.size();++i){
        long long acc1 = 0;
        for(int j = i; j <v.size(); ++j){
            acc1+= v[j];
            if(acc1<0) break;
            answer = answer>acc1?answer:acc1;
        }
    }
    for(int i = 0; i < v.size();++i){
        long long acc1 = 0;
        for(int j = i; j <v.size(); ++j){
            acc1-= v[j];
            if(acc1<0) break;
            answer = answer>acc1?answer:acc1;
        }
    }
    return answer;
}