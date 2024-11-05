#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#define MAX_N 8
using namespace std;

int n, k, u, d;
int grid[MAX_N][MAX_N];
int max_cnt;
int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, 1, 0, -1};

bool isCanGo(int x, int y, int dist) {
    return (x >= 0 && x < n && y >= 0 && y < n && dist >= u && dist <= d);
}


int bfs(int x, int y, bool (&visited)[MAX_N][MAX_N]) {
    queue<pair<int,int>> q = queue<pair<int,int>>();
    int move_cnt = 0;

    if (visited[x][y]) return 0;
    
    q.push(make_pair(x, y));
    visited[x][y] = true;
    move_cnt++;

    while (!q.empty()) {
        int cur_x, cur_y;
        tie(cur_x, cur_y) = q.front();
        q.pop();

        for (int i =0; i < 4; i++) {
            int new_x = cur_x + dir_x[i];
            int new_y = cur_y + dir_y[i];
            int dist = abs(grid[cur_x][cur_y] - grid[new_x][new_y]);
            if (isCanGo(new_x, new_y, dist) && !visited[new_x][new_y]) {
                q.push(make_pair(new_x, new_y));
                visited[new_x][new_y] = true;
                move_cnt++;
            }
        }
    }

    return move_cnt;
}

vector<int> pos;

void recursion(int cur_num) {
    if (cur_num == k) {
        bool visited[MAX_N][MAX_N] = {false};
        int cnt = 0;
        
        for (auto num : pos) {
            cnt += bfs(num / n, num % n, visited);
        }
        max_cnt = max(max_cnt, cnt);
        return;
    }
    for (int i = 0; i < n*n; i++) {
        pos.push_back(i);
        recursion(cur_num + 1);
        pos.pop_back();
    }
}

int main() {
    cin >> n >> k >> u >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    recursion(0);
    

    cout << max_cnt;











    return 0;
}