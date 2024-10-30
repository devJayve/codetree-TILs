#include <iostream>
#define MAX_N 50
using namespace std;

int N, M;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {1,0,-1,0};

bool isCanGo(int x, int y, int k) {
    return (!visited[x][y] && grid[x][y] > k && x >= 0 && x < N && y >= 0 && y < M);
}

void dfs(int x, int y, int k) {
    if (grid[x][y] <= k) return;
    
    visited[x][y] = true;
    
    for (int i = 0; i < 4; i++) {
        int new_x = x + dir_x[i];
        int new_y = y + dir_y[i];
        if (isCanGo(new_x, new_y, k)) {
            dfs(new_x, new_y, k);
        }
    }
}

void clear() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visited[i][j] = false;
}

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];
    
    
    int max_cnt = 0;
    int max_k = 0;
    
    for (int k = 1; k < 100; k++) {
        int safe_cnt = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (isCanGo(i, j, k)) {
                    dfs(i, j, k);
                    safe_cnt++;
                }
            }
        }
        if (safe_cnt > max_cnt) {
            max_cnt = safe_cnt;
            max_k = k;
        }
        clear();
    }
    
    cout << max_k << " " << max_cnt;
    
    
    return 0;
}