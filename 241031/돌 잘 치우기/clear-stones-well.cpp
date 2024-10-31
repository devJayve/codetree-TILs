#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#define MAX_N 100
using namespace std;

int N;
int grid[MAX_N+1][MAX_N+1];
int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {1,0,-1,0};

bool isCanGo(int x, int y, bool (&visited)[MAX_N + 1][MAX_N + 1]) {
    return (x > 0 && x <= N && y > 0 && y <= N && !visited[x][y]);
}

int bfs(int start_x, int start_y, int m) {
    priority_queue<tuple<int,int,int>> pq = priority_queue<tuple<int,int,int>>();
    bool visited[MAX_N + 1][MAX_N + 1] = {false, };
    int visit_cnt = 0;
    
    pq.push(make_tuple(-grid[start_x][start_y], start_x, start_y));
    
    while (!pq.empty()) {
        int weight, x, y;
        tie(weight, x, y) = pq.top();
        pq.pop();
        
        if (grid[x][y] && m == 0) continue;
        if (grid[x][y]) m--;
        
        if (visited[x][y]) continue;
        visited[x][y] = true;
        visit_cnt++;
        
        for (int i = 0; i < 4; i++) {
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            if (isCanGo(new_x, new_y, visited)) {
                pq.push(make_tuple(-grid[new_x][new_y], new_x, new_y));
            }
        }
    }
    
    return visit_cnt;
}

int main() {
    int K, M;
    int x, y;
    int ans = 0;
    
    cin >> N >> K >> M;
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> grid[i][j];
    
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        int res = bfs(x, y, M);
        ans = max(ans, res);
    }
    
    cout << ans;
    
    return 0;
}