#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    vector<int>* L = &arrayA;
    vector<int>* R = &arrayB;
    for(int t =0; t<2;++t){
        int aMin = 100000001;
        for(int i = 0; i < L->size(); ++i){
            aMin = min(aMin,(*L)[i]);
        }
        int LA = 0;
        for(int i = aMin; i>1;--i){
            for(int j = 0; j<(*L).size(); ++j){
                if((*L)[j]%i)
                    goto FAIL1;
            }
            LA = i;
            break;
            FAIL1:;
        }
        cout<<LA<<endl;
        if(LA == 0){
            goto FAIL;
        }
        for(int i =0; i < (*R).size(); ++i){
            if((*R)[i]%LA == 0){
                goto FAIL;
            }
        }
        
        answer = max(answer,LA);
        FAIL:;
        swap(L,R);
    }
    
    
    return answer;
}