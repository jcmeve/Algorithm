#include <string>
#include <vector>

using namespace std;
int g_total_holes = 0;
vector<vector<int>>* g_key;
vector<vector<int>>* g_lock;
int key_size = 0;
int lock_size = 0;

void rotate(){
    int n = key_size;
    vector<vector<int>> rotated(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotated[j][n - 1 - i] = (*g_key)[i][j];
        }
    }
    *g_key = rotated;
}
bool check(){
    for(int i = -key_size+1; i < lock_size; ++i){
        for(int j = -key_size+1; j < lock_size; ++j){
            int filled_holes = 0;
            bool is_match = true;
            for(int y = 0; y<lock_size; ++y){
                for(int x = 0; x<lock_size; ++x){
                    int lock_val = (*g_lock)[y][x];
                    int key_y = y - i;
                    int key_x = x - j;
                    int key_val = 0;
                    
                    if (key_y >= 0 && key_y < key_size && key_x >= 0 && key_x < key_size) {
                        key_val = (*g_key)[key_y][key_x];
                    }
                    
                    if (lock_val == 1 && key_val == 1) {
                        is_match = false;
                        break;
                    }
                    
                    if (lock_val == 0 && key_val == 1) {
                        filled_holes++;
                    }
                }
                if (!is_match) break;
            }
            if (is_match && filled_holes == g_total_holes) return true;
        }
    }
    return false;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    g_key = &key;
    g_lock = &lock;
    
    g_total_holes = 0;
    for (int i = 0; i < lock.size(); ++i) {
        for (int j = 0; j < lock[0].size(); ++j) {
            if (lock[i][j] == 0) g_total_holes++;
        }
    }
    key_size = key.size();
    lock_size = lock.size();
    
    
    
    if(check())return true; 
    for(int i = 0;i<3;++i){
        rotate();
        if(check())return true; 
    }
    
    return false;
}