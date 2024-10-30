#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_N 25
using namespace std;

int N;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int cnt;

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

bool isCanGo(int x, int y) {
    return (!visited[x][y] && grid[x][y] && x >= 0 && x < N && y >=0 && y < N);
}


void dfs(int x, int y) {
    if (grid[x][y] != 1) return;
    cnt++;
    visited[x][y] = true;
    
    for (int i = 0; i < 4; i++) {
        int new_x = x + dir_x[i];
        int new_y = y + dir_y[i];
        
        if (isCanGo(new_x, new_y)) {
            dfs(new_x, new_y);
        }
    }
}

int main() {
    priority_queue<int> pq = priority_queue<int>();
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];
    

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(!visited[i][j] && grid[i][j]) dfs(i,j);
            if (cnt != 0) {
                pq.push(-cnt);
                cnt = 0;
            }
        }
    }
    
    cout << pq.size() << '\n';
    
    while (!pq.empty()) {
        cout << -(pq.top()) << '\n';
        pq.pop();
    }
    
    
    
    
    return 0;
}