#include <iostream>
#define MAX_N 100
using namespace std;

int N, M;
bool no_snake[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
bool isReachEnd;
int dir_x[2] = {0, 1};
int dir_y[2] = {1, 0};

bool isCanGo(int x, int y) {
    return (no_snake[x][y] && x < N && x >= 0 && y < M && y >= 0);
}

void dfs(int x, int y) {
    for (int i = 0; i < 2; i++) {
        int new_x = x + dir_x[i];
        int new_y = y + dir_y[i];
        
        if (new_x == N-1 && new_y == M-1) {
            isReachEnd = true;
            return;
        }
        
        if (isCanGo(new_x, new_y)) {
            dfs(new_x, new_y);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> no_snake[i][j];
    
    visited[0][0] = true;
    dfs(0, 0);
    
    cout << isReachEnd;
    
    return 0;
}