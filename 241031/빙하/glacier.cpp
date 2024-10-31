#include <iostream>
#include <queue>
#include <tuple>
#define MAX_N 200
using namespace std;

int N, M;
int grid[MAX_N][MAX_N];
int ans[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {1,0,-1,0};

bool isCanGo(int x, int y, bool (&visited)[MAX_N][MAX_N]) {
    return (x >= 0 && x < N && y >= 0 && y < M && !visited[x][y]);
}

bool isAroundIce(int x, int y) {
    queue<tuple<int,int,int>> q = queue<tuple<int,int,int>>();
    q.push(make_tuple(grid[x][y], x, y));
    bool visited[MAX_N][MAX_N] = {false , };
    
    while (!q.empty()) {
        int is_ice, x, y;
        tie(is_ice, x, y) = q.front();
        q.pop();
        
        if (x == 0 || y == 0 || x == N-1 || y == M-1) {
            return false;
        }
        
        for (int i = 0; i < 4; i++) {
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            if (isCanGo(new_x, new_y, visited) && !grid[new_x][new_y]) {
                visited[new_x][new_y] = true;
                q.push(make_tuple(grid[new_x][new_y], new_x, new_y));
            }
        }
    }
    return true;
}

int bfs(int x, int y) {
    queue<tuple<int,int,int>> q = queue<tuple<int,int,int>>();
    q.push(make_tuple(grid[x][y], x, y));
    int melt_cnt = 0;
    
    while(!q.empty()) {
        int is_ice, x, y;
        tie(is_ice, x, y) = q.front();
        q.pop();
        
        if (visited[x][y]) continue;
        if (isAroundIce(x, y)) continue;
        
        if (is_ice) {
            ans[x][y] = 0;
            melt_cnt++;
        }
        visited[x][y] = true;
        
        for (int i = 0; i < 4; i++) {
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            if (isCanGo(new_x, new_y, visited)) {
                q.push(make_tuple(grid[new_x][new_y], new_x, new_y));
            }
        }
    }
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            grid[i][j] = ans[i][j];
    
    return melt_cnt;
}

void printGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    int T = 0, size = 0;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            ans[i][j] = grid[i][j];
        }
    
//    cout << '\n';
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                int ans = bfs(i, j);
                if (ans != 0) {
                    size = ans;
                    T++;
//                    printGrid();
                }
                
            }
        }
    }
//    cout << '\n';
    
    cout << T << " " << size;
    
    return 0;
}