#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int n, int k) {
    int answer = 0;
    

    
    vector<int> nn;
    for(;n!=0;n/=k){
        nn.push_back(n%k);
    }

    reverse(nn.begin(),nn.end());
    
    for(int l =0; l < nn.size(); ++l){
        if(nn[l] == 0) continue;
        int r;
        for(r = l; r<nn.size(); ++r){
            if(nn[r] == 0) {break;}        
        }
        --r;
        long long target = 0;
        
        for(int i = l; i<=r; ++i){
            target*=10;
            target+=nn[i];
        }
        if(target == 1) goto FAIL;
        
        for(long long i = 2; i <=sqrt(target); ++i){
            if(target%i == 0)
                goto FAIL;
        }
        
        
        ++answer;
        FAIL:;
        l = r+1;
        
    }
    
    
    
    return answer;
}