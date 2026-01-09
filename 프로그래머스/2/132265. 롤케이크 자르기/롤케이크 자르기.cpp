#include <string>
#include <vector>
#include <set>
using namespace std;
vector<int>* g_topping;
int check(int i) {
    set<int>lset;
    set<int>rset;
    for (int l = i - 1; l >= 0; --l) {
        lset.insert((*g_topping)[l]);
    }
    for (int r = i; r < (*g_topping).size(); ++r) {
        rset.insert((*g_topping)[r]);
    }
    if (lset.size() == rset.size())
        return 0;
    if (lset.size() > rset.size())
        return 1;
    if (lset.size() < rset.size())
        return -1;
}


int solution(vector<int> topping) {
    g_topping = &topping;
    int answer = 0;
    //가짓수가 중요함 개수 말고
    //0...i-1 //// i ....end


    int l = 0, r = topping.size() - 1;
    int prevL = -123, prevR = -123;
    int m = (r + l) / 2;
    while (prevL != l || prevR != r) {
        m = (r + l) / 2;
        prevL = l;
        prevR = r;
        int ret = check(m);
        if (ret == 1) {
            r = m;
        }
        else if (ret == -1) {
            l = m;
        }
        else if (ret == 0) {
            goto FIND;
            break;
        }
    }
    return 0;
FIND:;
    int ll = l;
    int lr = m;


    while (ll != lr) {
        int target = (ll + lr) / 2;
        int ret = check(target);
        if (ret == 0) {
            lr = target;
        }
        else {
            if (ll == target) ll = target + 1;
            else ll = target;
        }
    }


    int rl = m;
    int rr = r;
    while (rl != rr) {

        int target = (rl + rr) / 2;
        int ret = check(target);
        if (ret == 0) {
            if (rl == target) rl = target + 1;
            else rl = target;
        }
        else {
            rr = target;

        }
    }


    return rr - ll;


    return answer;
}