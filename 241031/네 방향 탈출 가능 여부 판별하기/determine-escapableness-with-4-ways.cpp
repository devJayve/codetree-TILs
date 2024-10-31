#include <iostream>
#include <queue>
#include <tuple>
#define MAX_N 100
using namespace std;

int N, M;
int grid[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

bool isCanGo(int x, int y) {
    return (!visited[x][y] && grid[x][y] && x >= 0 && x < N && y >= 0 && y < M);
}

int bfs() {
    queue<pair<int,int>> q = queue<pair<int,int>>();
    q.push(make_pair(0, 0));
    
    
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        
        if (x == N-1 && y == M-1) {
            return 1;
        }
        
        if (visited[x][y]) continue;
        visited[x][y] = true;
        
        for (int i = 0; i < 4; i++) {
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            
            if (isCanGo(new_x, new_y)) {
                q.push(make_pair(new_x, new_y));
            }
        }
    }
    
    return 0;
}

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];
    
    int ans = bfs();
    cout << ans;
    
    
    return 0;
}