#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    for(;storey>0;storey/=10){
        int t = storey%10;
        if(t>5){
            storey+=10;
            answer+=10-t;
        }else if(t<5){
            answer+=t;
        }else{
            int next = storey/10%10;
            if(next>=5){
               storey+=10;
            answer+=10-t; 
            }else{
                answer+=t;
            }
                
        }
        
    }
    
    
    
    return answer;
}