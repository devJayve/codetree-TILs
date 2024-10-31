#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#define MAX_N 100
using namespace std;

int N, M;
int grid[MAX_N+1][MAX_N+1];
int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {1,0,-1,0};
bool visited[MAX_N + 1][MAX_N + 1];

bool isCanGo(int x, int y) {
    return (x > 0 && x <= N && y > 0 && y <= N && !visited[x][y]);
}

int calPriority(int x, int y) {
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        int new_x = x + dir_x[i];
        int new_y = y + dir_y[i];
        if (isCanGo(new_x, new_y) && !grid[new_x][new_y])
            ans++;
    }
    return ans;
}

int bfs(int start_x, int start_y) {
    priority_queue<tuple<int,int,int>> pq = priority_queue<tuple<int,int,int>>();
    int visit_cnt = 0;
    
    pq.push(make_tuple(5, start_x, start_y));
    
    while (!pq.empty()) {
        int weight, x, y;
        tie(weight, x, y) = pq.top();
        pq.pop();
        
        if (grid[x][y] && M == 0) continue;
        if (grid[x][y]) M--;
        
        if (visited[x][y]) continue;
        visited[x][y] = true;
        visit_cnt++;
//        cout << x << " " << y << '\n';
        
        for (int i = 0; i < 4; i++) {
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            if (isCanGo(new_x, new_y)) {
                int weight = 5;
                if (grid[new_x][new_y]) weight = calPriority(new_x, new_y);
                pq.push(make_tuple(weight, new_x, new_y));
            }
        }
    }
    
    return visit_cnt;
}

int main() {
    int K;
    int x, y;
    int ans = 0;
    
    cin >> N >> K >> M;
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> grid[i][j];
    
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        int res = bfs(x, y);
        ans += res;
    }
    
    cout << ans;
    
    return 0;
}