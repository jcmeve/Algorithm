#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == ' ') continue;
        bool check = (s[i] >= 'A' && s[i]<='Z');
        int temp = s[i]+n;
        if(check){
            while(temp>'Z')
                temp-=('z'-'a'+1);
        }else{
            while(temp>'z')
                temp-=('z'-'a'+1);
        }
        s[i] = temp;
        
    }
    return s;
}