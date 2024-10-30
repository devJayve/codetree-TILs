#include <iostream>
#include <algorithm>
#define MAX_N 100
using namespace std;

int N;
int grid[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int blk_cnt;
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

bool isCanGo(int x, int y, int num) {
    return (!visited[x][y] && grid[x][y] == num && x >= 0 && x < N && y >= 0 && y < N);
}

void dfs(int x, int y, int num) {
    if (grid[x][y] != num) return;
    visited[x][y] = true;
    blk_cnt++;
    
    for (int i = 0; i < 4; i++) {
        int new_x = x + dir_x[i];
        int new_y = y + dir_y[i];
        
        if (isCanGo(new_x, new_y, num)) {
            dfs(new_x, new_y, num);
        }
    }
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];
    
    int max_blk = 0;
    int bomb_blk_cnt = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num = grid[i][j];
            blk_cnt = 0;
            
            if (isCanGo(i, j, num)) {
                dfs(i, j, num);
                if (blk_cnt >= 4) bomb_blk_cnt++;
                max_blk = max(max_blk, blk_cnt);
            }
        }
    }
    
    cout << bomb_blk_cnt << " " << max_blk;
    
    return 0;
}