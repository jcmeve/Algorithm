#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int g_a, g_b;
vector<int> *g_g, *g_s, *g_w, *g_t;
bool f(long long t){
    long long acc_a=0;
    long long acc_b=0;
    long long acc_cap=0;
    for(int i = 0; i < (*g_g).size(); ++i){
        long long cap = (long long)(*g_w)[i] * ((t/(*g_t)[i]+1)/2);
        
        acc_a += min((long long)(*g_g)[i], cap);
        acc_b += min((long long)(*g_s)[i], cap);
        acc_cap += min((long long)(*g_g)[i] + (*g_s)[i], cap);
    }
    return (acc_a >= g_a && acc_b >= g_b && acc_cap >= g_a + g_b);
    
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    g_a = a;
    g_b = b;
    g_g = &g;
    g_s = &s;
    g_w = &w;
    g_t = &t;
    
    long long l = 0; long long r = 4000000000000000;
    while(l<=r){
        long long m = l + (r - l) / 2;
        if(f(m)){
            answer = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }
    return answer;
}