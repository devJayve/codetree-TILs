#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#define MAX_N 100
using namespace std;

int N;
int grid[MAX_N + 1][MAX_N + 1];

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

bool isCanGo(int x, int y, int limit, const bool (&visited)[MAX_N + 1][MAX_N + 1]) {
    return (x > 0 && x <= N && y > 0 && y <= N && !visited[x][y] && grid[x][y] < limit);
}

pair<int,int> bfs(int start_x, int start_y) {
    int weight, x = 0, y = 0;
    bool visited[MAX_N + 1][MAX_N + 1] = {false, };
    priority_queue<tuple<int,int,int>> pq = priority_queue<tuple<int,int,int>>();
    priority_queue<tuple<int,int,int>> ans = priority_queue<tuple<int,int,int>>();
    pq.push(make_tuple(grid[start_x][start_y], -start_x, -start_y));
    int limit = grid[start_x][start_y];
    
    int max_num = -1;
    
    while (!pq.empty()) {
        tie(weight, x , y) = pq.top();
        pq.pop();
        
        x = -x;
        y = -y;
        
        for (int i = 0; i < 4; i++) {
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            if (isCanGo(new_x, new_y, limit, visited)) {
                pq.push(make_tuple(grid[new_x][new_y], -new_x, -new_y));
                visited[new_x][new_y] = true;
                if (grid[new_x][new_y] >= max_num) {
                    max_num = grid[new_x][new_y];
                    ans.push(make_tuple(max_num, -new_x, -new_y));
                }
            }
        }
    }
    
    if (ans.empty()) return make_pair(x, y);
    
    int ans_weight, ans_x, ans_y;
    tie(ans_weight, ans_x, ans_y) = ans.top();
    return make_pair(-ans_x, -ans_y);
}

int main() {
    int K;
    int x, y;
    cin >> N >> K;
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> grid[i][j];
    
    cin >> x >> y;
    for (int i = 0; i < K; i++) {
        tie(x, y) = bfs(x, y);
    }
    cout << x << " " << y;
    
    return 0;
}