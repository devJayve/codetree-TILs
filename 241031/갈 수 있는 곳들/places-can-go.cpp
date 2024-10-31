#include <iostream>
#include <queue>
#include <tuple>
#define MAX_N 100
using namespace std;

int N, K;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {1,0,-1,0};

bool isCanGo(int x, int y) {
    return (x > 0 && x <= N && y > 0 && y <= N && !visited[x][y] && !grid[x][y]);
}

int bfs(int x, int y) {
    queue<pair<int,int>> q = queue<pair<int,int>>();
    int visit_cnt = 0;
    
    q.push(make_pair(x, y));
    
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        
        if (!isCanGo(x, y)) continue;
        visited[x][y] = true;
        visit_cnt++;
        
        for (int i = 0; i < 4; i++) {
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            if (isCanGo(new_x, new_y)) {
                q.push(make_pair(new_x, new_y));
            }
        }
    }
    
    return visit_cnt;
    
}

int main() {
    int x, y;
    int ans = 0;
    cin >> N >> K;
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> grid[i][j];
    
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        ans += bfs(x, y);
    }
    
    cout << ans;
    
    return 0;
}