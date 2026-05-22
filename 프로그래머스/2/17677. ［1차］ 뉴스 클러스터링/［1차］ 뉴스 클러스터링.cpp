#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    unordered_map<string,int> m1;
    unordered_map<string,int> m2;
    
    for(int i =0; i < str1.size()-1;++i){
        char c1 =toupper(str1[i]);
        char c2 =toupper(str1[i+1]);
        if(c2<'A'||c2>'Z'){
            ++i;continue;
        }
        if (c1 >= 'A' && c1 <= 'Z' && c2 >= 'A' && c2 <= 'Z') {
            string temp = "";
            temp += c1;
            temp += c2;
            m1[temp]++;
        }
    }
    for(int i =0; i < str2.size()-1;++i){
                
        char c1 =toupper(str2[i]);
        char c2 =toupper(str2[i+1]);
        if(c2<'A'||c2>'Z'){
            ++i;continue;
        }

        if (c1 >= 'A' && c1 <= 'Z' && c2 >= 'A' && c2 <= 'Z') {
            string temp = "";
            temp += c1;
            temp += c2;
            m2[temp]++;
        }
    }
    
    int c1 = 0;
    int c2 = 0;
    
    unordered_map<string, bool> all_keys;
    for (auto p : m1) all_keys[p.first] = true;
    for (auto p : m2) all_keys[p.first] = true;
    
    for (auto p : all_keys) {
        string key = p.first;
        int count1 = m1[key]; 
        int count2 = m2[key];
        
        c1 += min(count1, count2);
        c2 += max(count1, count2);
    }
    
    if (c2 == 0) return 65536;
    
    return (int)((double)c1 / c2 * 65536);
    
}