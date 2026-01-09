#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    
    for(char& c : word){
        switch(c){
            case  'A':
                c = 0;
                break;
            case  'E':
                c = 1;
                break;
            case  'I':
                c = 2;
                break;
            case  'O':
                c = 3;
                break;
            case  'U':
                c = 4;
                break;
            default:
                break;
        }
    }
    
    //EIO
    //A~AUUUU 781 -> 625 + 125 + 25 + 5 + 1
    //E 782
    //EIO
    //{(E-A)* sigma(0~5-i)781 + E(1)} +  {(I-A) *  EA~EAUUU(125+25+5+1)  + EI(1) }+ {(O-A) * EIA~EIAUU(25+5+1) +1}
    //781 + 1 + 312 + 1 + 93 + 1
    int pows[5] = {1,5,25,125,625};
    for(int i= 0; i < word.size(); ++i){
        int sigma = 0;
        for(int j = 0; j < 5-i; ++j){
            sigma += pows[j];
        }
        answer += word[i] * sigma+1;
    }
    return answer;
}