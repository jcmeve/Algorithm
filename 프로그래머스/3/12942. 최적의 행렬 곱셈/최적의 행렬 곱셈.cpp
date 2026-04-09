#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int dp[201][201];
vector<vector<int>>* g_matrix_sizes;
int f(int l, int r) {
    if(dp[l][r]) return dp[l][r];
    if(r-l<2)return 0;
    
    int ret = INT_MAX;
    for(int i =l;i<r-1;++i){
        int temp = f(l,i+1)+f(i+1,r)+((*g_matrix_sizes)[l][0]*(*g_matrix_sizes)[i][1]*(*g_matrix_sizes)[r-1][1]);
        ret = min(ret, temp);
    }
    dp[l][r] = ret;
    return ret;
}
int solution(vector<vector<int>> matrix_sizes) {
    g_matrix_sizes = &matrix_sizes;
    return f(0, matrix_sizes.size());
}
